<?php

function kalturacuepoints_player_embed_code($entry, $title, $description,
  $start_sec = 0, $end_sec = false,
  $partner = 518251, $sub_partner = 51825100, $player = 33905641,
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

  $playerId = 'kaltura_player_1485377760';
  $cache_st = '1485377760';

  // parameters to use with drupal t() to protect against xss
  $t_params = array(
    '@wid' => $player_width,
    '@hgt' => $player_height,
    '@title' => $title,
    '@descr' => $description,
    '@partner' => $partner,
    '@player' => $player,
    '@entry' => $entry,
    '@playrange' => $fv_playrange,
    '@playerId' => $playerId,
    '@cache_st' => $cache_st,
    );

  $str = _kalturacuepoints_embed_20170125();
  $clean_str = t($str, $t_params);
  return $clean_str;
}


function _kalturacuepoints_embed_20170125() {
$str = <<<EOD
<div id="kaltura_player_1452201175" style="width: @widpx; height: @hgtpx;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
<span itemprop="name" content="@title"></span>
<span itemprop="description" content="@descr"></span>
<span itemprop="duration" content=""></span>
<span itemprop="thumbnail" content=""></span>
<span itemprop="width" content="@wid"></span>
<span itemprop="height" content="@hgt"></span>
</div>
<script src="https://cdnapisec.kaltura.com/p/@partner/sp/@partner00/embedIframeJs/uiconf_id/9524271/partner_id/@partner?autoembed=true&entry_id=@entry&playerId=@playerId&cache_st=@cache_st&width=@wid&height=@hgt&flashvars[streamerType]=auto&@playrange"></script>
EOD;
return $str;
}


/**
 * example embed from KMC
 */
/*
<div id="kaltura_player_1485377760" style="width: 640px; height: 444px;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
<span itemprop="name" content="&quot;Wastage&quot; of Humans / Comrade Mauser / &quot;Victim of History&quot;"></span>
<span itemprop="description" content=""></span>
<span itemprop="duration" content="2709"></span>
<span itemprop="thumbnail" content="https://cfvod.kaltura.com/p/518251/sp/51825100/thumbnail/entry_id/1_y732of1y/version/100011"></span>
<span itemprop="width" content="640"></span>
<span itemprop="height" content="444"></span>
</div>
<script src="https://cdnapisec.kaltura.com/p/518251/sp/51825100/embedIframeJs/uiconf_id/33905641/partner_id/518251?autoembed=true&entry_id=1_y732of1y&playerId=kaltura_player_1485377760&cache_st=1485377760&width=640&height=444&flashvars[streamerType]=auto"></script>
 */
