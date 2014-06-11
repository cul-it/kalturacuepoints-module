
// This function is called by the KDP once the KDP is ready to begin interacting with
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

		findSegmentStartEnd : function() {
			// find the active segment
			// <div class="field-content  film-segment"><a href="/conversations/mueller/film/109/segment/1776" class="active"><span data-segmenttimes="00:20:53 to 00:38:22">Politics, Art, and Mass Movements</span></a></div>
			//alert ('findSegmentStartEnd')
			var active = jQuery("div.field-content.film-segment a.active span")[0];
			if (active != null) {
				var timerange = active.getAttribute("data-segmenttimes");
				var tparts = timerange.split(" ");
				var hhmmss = tparts[0].split(":");
				KalturaChaptersSample.segmentStart = (parseInt(hhmmss[0]) * 3600 + parseInt(hhmmss[1]) * 60 + parseInt(hhmmss[2])) * 1000;
				hhmmss = tparts[2].split(":");
				KalturaChaptersSample.segmentEnd = (parseInt(hhmmss[0]) * 3600 + parseInt(hhmmss[1]) * 60 + parseInt(hhmmss[2])) * 1000;
			}
		},

		playerPlaying: function() {
			if( KalturaChaptersSample.firstLoad ) {
				KalturaChaptersSample.firstLoad = false;
				KalturaChaptersSample.myPlayer.removeJsListener("playerPlayed", "KalturaChaptersSample.playerPlaying");
			}
		},

		doFirstPlay: function() {
			KalturaChaptersSample.firstLoad = true;
			KalturaChaptersSample.findSegmentStartEnd();
			KalturaChaptersSample.jumpToTime(KalturaChaptersSample.segmentStart);
			KalturaChaptersSample.myPlayer.removeJsListener("mediaReady", "KalturaChaptersSample.doFirstPlay");
			KalturaChaptersSample.clickOnPause();
		},

		clickOnPause: function() {
			var fram = document.getElementsByClassName("mwEmbedKalturaIframe");
			if (fram.length > 0) {
				var buts = fram[0].contentWindow.document.getElementsByClassName("playPauseBtn");
				if (buts.length > 0) {
					buts[0].click();	// simulate click to pause after seek
				}
				else {
					alert('no buts');
				}
			}
			else {
				alert('no fram');
			}
		},

		jumpToTime : function ( timesec ) {
			if (KalturaChaptersSample.myPlayer != null) {
				KalturaChaptersSample.myPlayer.sendNotification("doPlay");
				KalturaChaptersSample.myPlayer.sendNotification("doSeek", timesec/1000);
			}
		},

	updatePlayheadHandler : function(data, id) {
    // data = the player's progress time in seconds
    // id = the ID of the player that fired the notification;
    //alert('updatePlayhead ' + data + ':' + id);
    if ((KalturaChaptersSample.segmentEnd != null) && ((parseInt(data) * 1000) > KalturaChaptersSample.segmentEnd)) {
    	KalturaChaptersSample.myPlayer.sendNotification("doPause");
    }
	}
	}

	// called by the KDP once it is ready to interact with javascript on the page:
	function jsCallbackReady ( playerId ) {
		//alert('jsCallbackReady ' + playerId);
		var player = document.getElementById(playerId);
		if (!player) {
			var embed = document.getElementsByClassName("kaltura-embed")[0];
			var obj = embed.getElementsByTagName("object")[0];
			var playerId2 = obj.getAttribute('id');
			player = document.getElementById(playerId2);
		}
		window.kdp = player;
		//alert('from dynamic callback jsCallbackReady - supplied id: ' + playerId + ', real id: ' + playerId2);
		player.addJsListener("playerPlayed", "KalturaChaptersSample.playerPlaying");
		player.addJsListener("mediaReady", "KalturaChaptersSample.doFirstPlay");
		player.addJsListener("playerUpdatePlayhead", "KalturaChaptersSample.updatePlayheadHandler");
		player.setKDPAttribute("configProxy.flashvars","autoPlay","false");

		// Cache a reference to kaltura player in a variable within my scope (my object)
		KalturaChaptersSample.myPlayer = player;
	};

