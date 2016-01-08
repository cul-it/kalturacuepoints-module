<?php

function _kalturacuepoints_embed_20160107($player_width, $player_height, $title, $description, $partner, $player, $entry, $fv_playrange) {
$str = <<<EOD
<div id="kaltura_player_1452201175" style="width: {$player_width}px; height: {$player_height}px;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
<span itemprop="name" content="$title"></span>
<span itemprop="description" content="$description"></span>
<span itemprop="duration" content=""></span>
<span itemprop="thumbnail" content=""></span>
<span itemprop="width" content="{$player_width}"></span>
<span itemprop="height" content="{$player_height}"></span>
</div>
<script src="https://cdnapisec.kaltura.com/p/{$partner}/sp/{$partner}00/embedIframeJs/uiconf_id/9524271/partner_id/{$partner}?autoembed=true&entry_id={$entry}&playerId=kaltura_player_1452201175&cache_st=1452201175&width={$player_width}&height={$player_height}&flashvars[streamerType]=auto&{$fv_playrange}"></script>
EOD;
return $str;
}

/**
 * even newer Large Captioning Chapter Player Universal with support for https
 * @return string embed code formatted for Drupal format_string, t(), etc.
 *
 *  player ID 9524271
 */
function _kalturacuepoints_embed_2015($player_width, $player_height, $title, $description, $partner, $player, $entry, $fv_playrange) {
$str = <<<EOD
<div id="kaltura_player_1445872886" style="width: {$player_width}px; height: {$player_height}px;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
<span itemprop="name" content="$title""></span>
<span itemprop="description" content="$description"></span>
<span itemprop="duration" content=""></span>
<span itemprop="thumbnail" content=""></span>
<span itemprop="width" content="{$player_width}"></span>
<span itemprop="height" content="{$player_height}"></span>
</div>
<script src="//cdnsecakmi.kaltura.com/p/{$partner}/sp/{$partner}00/embedIframeJs/uiconf_id/{$player}/partner_id/{$partner}?autoembed=true&entry_id={$entry}&playerId=kaltura_player_1445872886&cache_st=1445872886&width={$player_width}&height={$player_height}&flashvars[streamerType]=auto&{$fv_playrange}"></script>
EOD;
return $str;
}


function kalturacuepoints_player_embed_code($entry, $title, $description,
  $start_sec = 0, $end_sec = false,
  $partner = 518251, $sub_partner = 51825100, $player = 9524271 /*7929281*/,
  $player_width = 400, $player_height = 289 ) {
  // emit code for a kaltura player
  // $entry is the id of the asset like 1_t9lgbvo6
  $playrange = "mediaProxy.mediaPlayFrom=$start_sec";
  if ($end_sec !== false) {
    $playrange .= "&mediaProxy.mediaPlayTo=$end_sec";
    }
  $fv_playrange="flashvars[mediaProxy.mediaPlayFrom]=$start_sec";
  if ($end_sec !== FALSE) {
    $fv_playrange .= "&flashvars[mediaProxy.mediaPlayTo]=$end_sec";
  }

  // parameters to use with drupal t() to protect against xss
  $t_params = array(
    '@wid' => $player_width,
    '@widpx' => $player_width . 'px',   // embed needs number with px suffix
    '@hgt' => $player_height,
    '@hgtpx' => $player_height . 'px',  // embed needs number with px suffix
    '@title' => $title,
    '@descr' => $description,
    '@partner' => $partner,
    '@player' => $player,
    '@entry' => $entry,
    '@playrange' => $fv_playrange,
    );

  $str = _kalturacuepoints_embed_20160108();
  $clean_str = t($str, $t_params);
  dpm($str, 'undoctored string');
  dpm($clean_str, 'string after t()');
  return $str;
}


function _kalturacuepoints_embed_20160108() {
$str = <<<EOD
<div id="kaltura_player_1452201175" style="width: @widpx; height: @hgtpx;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
<span itemprop="name" content="@title"></span>
<span itemprop="description" content="@descr"></span>
<span itemprop="duration" content=""></span>
<span itemprop="thumbnail" content=""></span>
<span itemprop="width" content="@wid"></span>
<span itemprop="height" content="@hgt"></span>
</div>
<script src="https://cdnapisec.kaltura.com/p/@partner/sp/@partner00/embedIframeJs/uiconf_id/9524271/partner_id/@partner?autoembed=true&entry_id=@entry&playerId=kaltura_player_1452201175&cache_st=1452201175&width=@wid&height=@hgt&flashvars[streamerType]=auto&@playrange></script>
EOD;
return $str;
}
