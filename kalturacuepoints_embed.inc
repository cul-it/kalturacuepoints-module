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

  $playerId = 'kaltura_player_1506540327';
  $cache_st = '1506540327';

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

function _kalturacuepoints_embed_1506540327() {
  // Large Captioning Chaptering Player Universal - Kaltura Support
  // KMC Studio ID: 33905641
  // player internal id: kaltura_player_1506540327
  //
  $str = <<<EOD
  <div id="kaltura_player_1506540327" style="width: 640px; height: 444px;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
<span itemprop="name" content="Mind, Power, Castration"></span>
<span itemprop="description" content="&lt;p&gt;Here Müller and Kluge explicitly address a theme that is latently present in many of their conversations: the relation of intellectuals to reigning political power. Given his many writings on Frederick the Great, it is not surprising that Müller begins the discussion with the “love-hate” relationship between the 18th Century Prussian King and the French Philosopher Voltaire. Moving to the 20th Century, the conversation then focuses for the most part on intellectuals and their relationship to totalitarian regimes. An initial sketch of an encounter between the Russian writer Maxim Gorky and Vladimir Lenin in the post-revolutionary Soviet Union segues into a treatment of the German writer Ernst Jünger in the Third Reich (1933-1945). Müller follows this up with remarks about the importance of Jünger for his own thinking as a writer before and after the founding of the German Democratic Republic. The final section of the interview revolves around  the playwright Bertolt Brecht and his role as a critical intellectual/artist in the early days of the GDR that concludes in turn with an intriguing exchange between Müller and Kluge on the potential of theater to resist the “acceleration of time.” &lt;/p&gt;
&lt;br /&gt; &lt;P&gt; Müller und Kluge wenden sich hier einem Thema zu, das in vielen Gesprächen latent vorhanden ist: dem Verhältnis von Intellektuellen und Macht. Bei seinen vielen Texten über Friedrich den Großen ist es nicht überraschend, dass Müller das Gespräch mit der Hassliebe zwischen dem Preußenkönig des 18. Jahrhunderts und Voltaire eröffnet. Das Gespräch wendet sich dann dem 20. Jahrhundert zu und konzentriert sich größtenteils auf das Verhältnis von Inttellektuellen zu totalitären Regimes. Einer anfänglichen Skizze einer Begegnung zwischen dem russischen Schriftsteller Maxim Gorki und Wladimir I. Lenin in der nachrevolutionären Sowjetunion folgt das Beispiel Ernst Jüngers im Dritten Reich. Müller beschreibt dann die Bedeutung Jüngers für sein eigenes Denken als Schriftsteller vor und nach der Gründung der DDR. Der letzte Abschnitt  des Interviews dreht sich um den Dramatiker Bertolt Brecht und seine Rolle als kritischer Intellektueller / Künstler in den frühen Tagen der DDR und führt dann zu einem fesselnden Austausch zwischen Müller und Kluge über die Möglichkeit des Theaters der &quot;Beschleunigung der Zeit“ Widerstand zu leisten. &lt;/P&gt;"></span>
<span itemprop="duration" content="1521"></span>
<span itemprop="thumbnail" content="https://cfvod.kaltura.com/p/518251/sp/51825100/thumbnail/entry_id/1_vuazxshh/version/100011"></span>
<span itemprop="width" content="640"></span>
<span itemprop="height" content="444"></span>
</div>
<script src="https://cdnapisec.kaltura.com/p/518251/sp/51825100/embedIframeJs/uiconf_id/33905641/partner_id/518251?autoembed=true&entry_id=1_vuazxshh&playerId=kaltura_player_1506540327&cache_st=1506540327&width=640&height=444&flashvars[streamerType]=auto"></script>
EOD;
  return $str;
}


function _kalturacuepoints_embed_20170125() {
$str = <<<EOD
<div id="@playerId" style="width: @widpx; height: @hgtpx;" itemprop="video" itemscope itemtype="http://schema.org/VideoObject">
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
