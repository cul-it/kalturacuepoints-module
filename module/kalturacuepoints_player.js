//reference copy of kaltura_player.js from cornellcast
// This function is called by the KDP once the KDP is ready to begin interacting with
// javascript to see if javascript is also ready. If true is returned, KDP continues and
// calls jsCallbackReady (see below), otherwise it continues to try every 100ms. The
// name of the function is set using the "jsInterfaceReady" flashvar. If you do not set
// this flashvar at all, jsCallbackReady will be called immediatly (not recommended).
function delayStart() {
	kdp.sendNotification("doPlay");
	kdp.sendNotification("doSeek", CC.startSecs);
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
$(function() {
// event handler is attached to <ul> so that <li>'s can be updated via ajax and
// will continue to work
$("#sample_playlist").click(function(e) {
// "window.kdp" instead of "kdp" to prevent possible "undefined" error
if(window.kdp) {
if(kdp_embed.auto_continue) {
kdp.addJsListener("playerPlayEnd", "playNextVid");
}
var entry_id = $(e.target).parents("li").attr("id");
kdp.sendNotification("changeMedia", {entryId: entry_id});
location.hash = kdp_embed.url_param_name + "=" + entry_id;
}
else {
alert("player not ready yet");
// optionally, store desired entry_id in var + add to jsCallbackReady a
// listener for kdpReady/ kdpEmpty and auto load click on entry as soon as
// player is ready for it (some consider remembering the entry id a potential
// UX issue because the wait could be several seconds long). If you do this,
// move the "var entry_id..." line to above the if clause.
}
return false;
});
});
function playNextVid() {
window.now_playing = kdp.evaluate("{mediaProxy.entry.id}");
var next_entry_id = $("#" + now_playing).next().attr("id");
if(next_entry_id.length) {
kdp.sendNotification("changeMedia", {entryId: next_entry_id});
location.hash = "entryId=" + next_entry_id;
}
}
