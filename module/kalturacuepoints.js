(function ($) {
  $(document).ready(function(){
    var window.kdp = document.getElementById('#kaltura_player_9511'); // already parsed
    var timesec = 13;
    if (kdp.length !== 0) {
 				kdp.sendNotification("doPlay");
				kdp.sendNotification("doSeek", timesec/1000);
    }
  });
})(jQuery);

// This function is called by the KDP once the KDP is ready to begin interacting with
// javascript to see if javascript is also ready. If true is returned, KDP continues and
// calls jsCallbackReady (see below), otherwise it continues to try every 100ms. The
// name of the function is set using the "jsInterfaceReady" flashvar. If you do not set
// this flashvar at all, jsCallbackReady will be called immediatly (not recommended).
function kalturacuepoints_ready() {
	alert('kalturacuepoints_ready');
}

function jsInterfaceReady() {
	return true;
	}

// jsCallbackReady is called by KDP as soon as KDP is ready to begin interacting with
// javascript. We place it in head to ensure that it's always available before KDP calls
// it (depending on page structure, KDP may call jsCallbackReady before DOM is ready)
function jsCallbackReady(player_id) {

	// create a (global) reference to the KDP so we don't have to repeat querying the dom.
	// we use the "window." prefix as a convention to point out that this var is global
	window.kdp = document.getElementById(player_id);
	kdp.addJsListener("playerPlayEnd", "tellFlashPlayerNextVideoID");
	var autoplay = kdp_embed.auto_play;
	if ((CC.autoplay == 0) || (CC.autoplay == "false") || (CC.autoplay == false)) {
		autoplay = false;
		}
	if(autoplay) {
		kdp.setKDPAttribute("configProxy.flashvars", "autoPlay", "true");
		}
	if (CC.startSecs > 0) {
		kdp.setKDPAttribute('mediaProxy', 'mediaPlayFrom', CC.startSecs);
		}
	if (CC.endSecs > 0) {
		kdp.setKDPAttribute('mediaProxy', 'mediaPlayTo', CC.endSecs);
		}
	}

	var KalturaChaptersSample = {

		myPlayer : null,
		currentCue : null,
		firstLoad : false,

		playerPlaying: function() {
			if( KalturaChaptersSample.firstLoad ) {
				KalturaChaptersSample.firstLoad = false;
				var lastIndex = document.URL.lastIndexOf('enterprise');

				var chapterNum = 0;

				if(lastIndex != -1)
				{
					xUrl = document.URL.substr(lastIndex + 11); //Remove the 'enterprise/' from the string
					urlParts = xUrl.split("-");
					chapterNum = urlParts[0];
				}

				var element = $('ul li a').get(chapterNum);
				this.switchActiveCue(element.id);
				this.jumpToTime(element.getAttribute("data-chapterStartTime"));

				setTimeout( function() {
					KalturaChaptersSample.myPlayer.sendNotification("doPause");
				}, 50);
			}
		},

		doFirstPlay: function() {
			KalturaChaptersSample.firstLoad = true;
			this.myPlayer.sendNotification("doPlay");
		},

		jumpToTime : function ( timesec ) {
			if (this.myPlayer != null) {
				this.myPlayer.sendNotification("doPlay");
				this.myPlayer.sendNotification("doSeek", timesec/1000);
			}
		},

		switchActiveCue : function ( newId ) {
			if (this.currentCue != null) this.currentCue.className = '';
			this.currentCue = document.getElementById(newId);
			this.currentCue.className = 'selected';
			console.log(newId);
		},

		cuePointHandler : function( qPoint ) {
			if(this.firstLoad == false)
			{
				var cuePoint = $('#cp'+qPoint.cuePoint.id);

				console.log(cuePoint);
				this.changePageData(cuePoint);
			}
		 },

		//Changes all the data on the page - selecting the chapter, changing the content and the URL
		changePageData : function(cuePoint){
			var chapterName = cuePoint.attr("data-chapterName");

			jQuery('#ctitle').text(cuePoint.attr("data-chapterTitle"));
			jQuery('#cimage').attr("src", cuePoint.attr("data-chapterThumb"));
			jQuery('#ctags').text("Chapter Tags: " + cuePoint.attr("data-chapterTags"));
			this.switchActiveCue(cuePoint.attr("id"));

			//Change the URL without refreshing the page
			window.history.pushState("CuePointClicked", "CuePointClicked", chapterName);

			try
			{
				window.history.pushState("CuePointClicked", "CuePointClicked", chapterName);
			}
			catch(err)
			{

			}
		}
	}

	// called by the KDP once it is ready to interact with javascript on the page:
	var jsCallbackReady = function( playerId ) {
		var player = document.getElementById(playerId);
		player.addJsListener("playerPlayed", "KalturaChaptersSample.playerPlaying");
		player.addJsListener("cuePointReached", "KalturaChaptersSample.cuePointHandler");
		player.addJsListener("mediaReady", "KalturaChaptersSample.doFirstPlay");

		// Cache a reference to kaltura player in a variable within my scope (my object)
		KalturaChaptersSample.myPlayer = player;

		//myPlayer.addJsListener("adOpportunity", "cuePointHandler"); used for Ad Cue Points
	};

    jQuery.noConflict();
    jQuery(document).ready(function() {
		jQuery('#chapters a').click(function(e) {
			var chapter = jQuery(e.target);

			//Change the page and skip to the chapter
			KalturaChaptersSample.changePageData(chapter);
			KalturaChaptersSample.jumpToTime(chapter.attr("data-chapterStartTime"));

			//Prevent redirect on the page
			if(e.preventDefault) e.preventDefault();
			e.returnValue = false; //Fix for IE

			return false;
		});
	});
