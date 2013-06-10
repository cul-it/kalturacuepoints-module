﻿// This function is called by the KDP once the KDP is ready to begin interacting with
// javascript to see if javascript is also ready. If true is returned, KDP continues and
// calls jsCallbackReady (see below), otherwise it continues to try every 100ms. The
// name of the function is set using the "jsInterfaceReady" flashvar. If you do not set
// this flashvar at all, jsCallbackReady will be called immediatly (not recommended).
function kalturacuepoints_ready() {
	alert('kalturacuepoints_ready');
}

function jsInterfaceReady() {
	alert('jsInterfaceReady');
	return true;
	}

var KalturaChaptersSample = {

		myPlayer : null,
		currentCue : null,
		firstLoad : false,
		segmentStart : null,
		segmentEnd : null,

		playerPlaying: function() {
			if( KalturaChaptersSample.firstLoad ) {
				KalturaChaptersSample.firstLoad = false;

				// find the active segment
				// <div class="field-content  film-segment"><a href="/conversations/mueller/film/109/segment/1776" class="active"><span data-segmenttimes="00:20:53 to 00:38:22">Politics, Art, and Mass Movements</span></a></div>
				var active = jQuery("div.film-segment a.active span")[0];
				var timerange = active.getAttribute("data-segmenttimes");
				var tparts = timerange.split(" ");
				var hhmmss = tparts[0].split(":");
				this.segmentStart = (hhmmss[0] * 3600 + hhmmss[1] * 60 + hhmmss[2]) * 1000;
				hhmmss = tparts[2].split(":");
				this.segmentEnd = (hhmmss[0] * 3600 + hhmmss[1] * 60 + hhmmss[2]) * 1000;

				this.jumpToTime(this.segmentStart);
			}
		},

		doFirstPlay: function() {
			KalturaChaptersSample.firstLoad = true;
			//this.myPlayer.sendNotification("doPlay");
			//this.jumpToTime(15000);
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
		},

	updatePlayheadHandler : function(data, id) {
    // data = the player's progress time in seconds
    // id = the ID of the player that fired the notification;
    //alert('updatePlayhead ' + data + ':' + id);
    if ((this.segmentEnd != null) && (data > this.segmentEnd)) {
    	KalturaChaptersSample.myPlayer.sendNotification("doPause");
    }
	}
	}

	// called by the KDP once it is ready to interact with javascript on the page:
	var jsCallbackReady = function( playerId ) {
		window.kdp = document.getElementById(playerId);
		var embed = document.getElementsByClassName("kaltura-embed")[0];
		var obj = embed.getElementsByTagName("object")[0];
		var playerId2 = obj.getAttribute('id');
		var player = document.getElementById(playerId2);
		//alert(playerId + ' from dynamic callback - real id: ' + playerId2);
		player.addJsListener("playerPlayed", "KalturaChaptersSample.playerPlaying");
		player.addJsListener("cuePointReached", "KalturaChaptersSample.cuePointHandler");
		player.addJsListener("mediaReady", "KalturaChaptersSample.doFirstPlay");
		player.addJsListener("playerUpdatePlayhead", "KalturaChaptersSample.updatePlayheadHandler");

		// Cache a reference to kaltura player in a variable within my scope (my object)
		KalturaChaptersSample.myPlayer = player;

		//player.sendNotification("doPlay");
		player.sendNotification('doSeek', parseFloat('5.992'));
		player.jumpToTime('5992');

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

(function ($) {
  $(document).ready(function(){
		//jsCallbackReady('#kaltura_player_9511');
		// var embed = document.getElementsByClassName("kaltura-embed")[0];
		// var obj = embed.getElementsByTagName("object")[0];
		// var playerId = obj.getAttribute('id');
		// Seek to: <input type="text" size="4" id="seekto" value="25"/><button onclick="$('#kdp3').get(0).sendNotification('doSeek', parseFloat($('#seekto').val()));return false;">Seek</button>
		// obj.sendNotificaton('doSeek', parseFloat(13));
		//jsCallbackReady(playerId);
/*		var player = document.getElementById(playerId);
		if (player != null) {
			player.sendNotification("doPlay");
			player.addJsListener("playerPlayed", "KalturaChaptersSample.playerPlaying");
			player.addJsListener("cuePointReached", "KalturaChaptersSample.cuePointHandler");
			player.addJsListener("mediaReady", "KalturaChaptersSample.doFirstPlay");

			// Cache a reference to kaltura player in a variable within my scope (my object)
			KalturaChaptersSample.myPlayer = player;
		}

	window.KalturaChaptersSample.jumpToTime(13);
*/  });
})(jQuery);


