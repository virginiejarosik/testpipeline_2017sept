<?php
$locations = array("JewishAgency/English/About/Press+Room", "JewishAgency/English/About/Videos", "JewishAgency/English/About/Our+Partners", "companies", "business", "JewishAgency/English/Aliyah/Contact+Addresses", "JewishAgency/English/Aliyah/Aliyah%20Info", "JewishAgency/English/Aliyah/Links", "JewishAgency/English/Aliyah/Partnerships", "JewishAgency/English/Connecting+to+Israel/Community+Services", "JewishAgency/English/Connecting%20to%20Israel/Reshet_il", "JewishAgency/English/Connecting+to+Israel", "JewishAgency/English/Israel/Educational", "JewishAgency/English/Contact+Us", "JewishAgency/English/Aliyah/Aliyah%20Info/aliyah-form", "English/About/Videos/aliyah-rescue", "JewishAgency/English/About/Updates", "JewishAgency/English/Aliyah/job", "NR/exeres/E44B7BBD-E58C-46DE-93B1-262589F4176D","JewishAgency/English/Jewish+Education/Compelling+Content/Jewish+Time/Festivals+and+Memorial+Days/Pesach/Web+Perspectives/The+Haggadah.htm", "JewishAgency/English/Aliyah/Contact+Addresses/Representatives/Europe.htm","JewishAgency/English/Jewish+Education/Compelling+Content/Eye+on+Israel/Places+in+Israel","JewishAgency/English/Jewish+Education/Compelling+Content/Eye+on+Israel/Israeli+Culture", "NR/exeres/C2F2D080-D285-476E-B6EF-FA43D5E90755","nr/exeres/ef51326b-a217-4e16-8b3c-61f996184077,frameless.htm?nrmode=published","JewishAgency/English/Jewish+Education/Compelling+Content/Eye+on+Israel/Current+Issues/Jewish+Soldiers+and+Prisoners+of+War+during+World+War+II.htm","JewishAgency/English/Aliyah/Aliyah+Info","JewishAgency/English/Jewish+Education/focus+areas/halavudvash","JewishAgency/English/Jewish+Education/Compelling+Content/Worldwide+Community/Anti-semitism/Kristallnacht++The+Night+of+Broken+Glass.htm","nr/exeres/9b51d5c7-2339-46dc-b55b-f744257951bc,frameless.htm?nrmode=published","nr/exeres/50ca6215-e1b0-4ace-be09-8dac52473c6f,frameless.htm?nrmode=published","JewishAgency/English/Jewish+Education/Compelling+Content/Eye+on+Israel/British+Rule","JewishAgency/English/Jewish+Education/Compelling+Content/Eye+on+Israel/Society/9)The+Role+of+the+Military+in+Israel.htm","NR/exeres/52DE4DDF-1EC6-4230-B1C9-D80AAED28241","JewishAgency/English/Aliyah/Aliyah+Info/Thoughts+on+Aliyah+and+Israel/Articles+about+Israel/Education+in+Israel.htm","JewishAgency/English/Jewish+Education/Compelling+Content/Eye+on+Israel/Israeli+Culture/Gender+Roles+The+Changing+Role+of+Women.htm","JewishAgency/English/Aliyah/Absorpton+Options/Naale","JewishAgency/English/Jewish+Education/Compelling+Content/Jewish+Time/Festivals+and+Memorial+Days/Jerusalem+Day/Jerusalem+3000/Lecture+7++The+Destruction+of+the+Second+Temple.htm","JewishAgency/English/Connecting+to+Israel/Experience+Israel/Summer+Courses","JewishAgency/English/Aliyah/Aliyah+Info","NR/exeres/E6373CFC-BFE9-4FBA-8636-90F4704BAA44","JewishAgency/English/Aliyah/Absorpton+Options/Absorption+Centers/Haifa+15.htm","JewishAgency/English/Jewish+Education/Educational+Shlichut/pro/Midwest/Noe.htm","nr/exeres/6a7d1480-a44a-4ed2-acb0-ed141eb744ca,frameless.htm?nrmode=published","JewishAgency/English/Aliyah/Aliyah+Info/Thoughts+on+Aliyah+and+Israel/Articles+about+Israel/Teaching+English+-+Practical+Information.htm","JewishAgency/English/Jewish+Education/Educational+Resources/More+Educational+Resources/Leadership+Guides/discussion/Types_of_Discussion.htm","NR/exeres/EC3AD8B0-71DA-4FB2-B436-B3C07C3D2EB8");
$location = substr($_SERVER['REQUEST_URI'], 1);
if (substr($location, -1) == '/') {
  $location = substr($location, 0, -1);
}
if (in_array($location, $locations)) {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jafi.org/" . $location);
  die();
}

if ($_SERVER['SERVER_NAME'] == 'jaficamps.org' || $_SERVER['SERVER_NAME'] == 'www.jaficamps.org') {
  header("HTTP/1.1 301 Moved Permanently");
  if (substr($location, 0, 13) == '/jewishagency') {
      header("Location: http://www.jafi.org/" . $location);
  } else if ($location) {
      header("Location: http://www.jewishagency.org/" . $location);
  } else {
    header("Location: http://www.jewishagency.org/he/shlichim-israeli-emissaries/program/5415");
  }
  die();
}

if ($_SERVER['SERVER_NAME'] == 'youthfutures.org' || $_SERVER['SERVER_NAME'] == 'www.youthfutures.org') {
  header("HTTP/1.1 301 Moved Permanently");
  if (substr($location, 0, 7) == 'payroll' || substr($location, 0, 5) == 'tlush') {
    header("Location: https://payroll.malam.com/4570");
  } else {
    header("Location: http://yfcontact.wix.com/youthfutures");
  }
  die();
}

if ($_SERVER['SERVER_NAME'] == 'jafi.ru' || $_SERVER['SERVER_NAME'] == 'www.jafi.ru') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/ru/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'netivot.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/Netivot");
  die();
}

if ($_SERVER['SERVER_NAME'] == '2015.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://goo.gl/wdD1kP");
  die();
}

if ($_SERVER['SERVER_NAME'] == '2015heb.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://goo.gl/7Em6GL");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'chalav-udvash.org.il' || $_SERVER['SERVER_NAME'] == 'www.chalav-udvash.org.il') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/education/content/27061");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'westerngalilee.org.il' || $_SERVER['SERVER_NAME'] == 'www.westerngalilee.org.il') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/partnership2gether/content/33391");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'thejewishagency.org' || $_SERVER['SERVER_NAME'] == 'www.thejewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  if (substr($location, 0, 13) == '/jewishagency') {
      header("Location: http://www.jafi.org/" . $location);
  } else {
      header("Location: http://www.jewishagency.org/" . $location);
  }
  die();
}

if ($_SERVER['SERVER_NAME'] == 'schooltwinning.net' || $_SERVER['SERVER_NAME'] == 'www.schooltwinning.net') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/school-twinning/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'school-twinning.com' || $_SERVER['SERVER_NAME'] == 'www.school-twinning.com') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/school-twinning/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'jewishagency.org.il' || $_SERVER['SERVER_NAME'] == 'www.jewishagency.org.il') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'jewishagency.org.il' || $_SERVER['SERVER_NAME'] == 'www.jewishagency.org.il' || $_SERVER['SERVER_NAME'] == 'www.jewishagency.co.il' || $_SERVER['SERVER_NAME'] == 'www.jewishagency.co.il') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'voices.jewishagency.org') { 
	$url = parse_url($_SERVER['REQUEST_URI']);
  header('Location: http://www.jewishagency.org/voices'.$url['path'] . (isset($url['query']) && $url['query'] ? '?'.$url['query'] : ''), true, 301);
  die();
}

if ($_SERVER['SERVER_NAME'] == 'renaissance.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'babait-beyahad.org.il') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/aliyah/program/454");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'www.aliyah.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/aliyah");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'israelprograms.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/experience-israel");
  die();
}


if ($_SERVER['SERVER_NAME'] == 'youthfutures.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/youthfutures");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'laad.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/jewish-social-action/story/9891");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'relay.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'christianfriends.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/christian-friends");
  die();
}


if ($_SERVER['SERVER_NAME'] == 'jewishagency.co.il') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'globalleadership.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/experience-israel/program/43911");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'impact.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/inside-jewish-agency/impact-and-measurement-reports");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'haifa-boston.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/p2g-lobby");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'agenciajudia.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/es/");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'ed.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  header("Location: http://www.jewishagency.org/he/p2g-lobby");
  die();
}

if ($_SERVER['SERVER_NAME'] == 'hitchadshut.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  $redirect_array = array('2011/06/28/' => 'http://www.jewishagency.org/he/israel-your-community/program/17556',  
      '2012/07/25/' => 'http://www.jewishagency.org/he/blog/7606/article/17006',  
      '2011/09/27/' => 'http://www.jewishagency.org/he/blog/7606/article/17021',  
      '2010/11/25/' => 'http://www.jewishagency.org/he/jewish-renaissance/content/18701',  
      '2011/11/03/' => 'http://www.jewishagency.org/he/blog/7606/article/17561',  
      '2011/11/10/' => 'http://www.jewishagency.org/he/blog/7606/article/17566',  
      '2011/01/20/' => 'http://www.jewishagency.org/he/blog/7606/article/17571',  
      '2011/09/19/' => 'http://www.jewishagency.org/he/blog/7606/article/18706',  
      '2011/06/26/' => 'http://www.jewishagency.org/he/blog/7606/article/18711',  
      '2012/03/01/' => 'http://www.jewishagency.org/he/blog/7606/article/18716',  
      '2011/09/21/' => 'http://www.jewishagency.org/he/blog/7606/article/18721',  
      '2011/07/13/' => 'http://www.jewishagency.org/he/node/17221',  
      '2010/12/26/' => 'http://www.jewishagency.org/he/blog/7606/article/18726',  
      '2011/10/06/' => 'http://www.jewishagency.org/he/blog/7606/article/18731',  
      '2011/09/27/' => 'http://www.jewishagency.org/he/blog/7606/article/18736',  
      '2011/02/10/' => 'http://www.jewishagency.org/he/blog/7606/article/18741',  
      '2012/03/06/' => 'http://www.jewishagency.org/he/blog/7606/article/18746',  
      '2011/03/03/' => 'http://www.jewishagency.org/he/blog/7606/article/18751',  
      '2010/10/17/' => 'http://www.jewishagency.org/he/blog/7606/article/18756',  
      '2011/10/03/' => 'http://www.jewishagency.org/he/blog/7606/article/18761',  
      '2011/01/03/' => 'http://www.jewishagency.org/he/blog/7606/article/18771');
  if (isset($redirect_array[$location])) {
    header("Location: " . $redirect_array[$location]);
  } else {
    header("Location: http://www.jewishagency.org/he/israel-your-community/program/17556");
  }
  die();
}

if ($_SERVER['SERVER_NAME'] == 'p2g.jewishagency.org') {
  header("HTTP/1.1 301 Moved Permanently");
  $redirect_array = array('english/israelschools/biblequiz' => 'http://www.jewishagency.org/he/biblequiz',
      'biblequiz' => 'http://www.jewishagency.org/he/biblequiz',
      'english/partnerships/arad/' => 'http://www.jewishagency.org/arad', 
      'english/partnerships/arava/' => 'http://www.jewishagency.org/arava', 
      'english/partnerships/beersheva/' => 'http://www.jewishagency.org/beersheva', 
      'english/partnerships/beitshean/' => 'http://www.jewishagency.org/beitshean', 
      'english/partnerships/beitshemesh/' => 'http://www.jewishagency.org/beitshemesh', 
      'english/partnerships/carmiel/' => 'http://www.jewishagency.org/carmiel', 
      'english/partnerships/centralgalilee/' => 'http://www.jewishagency.org/centralgalilee', 
      'english/partnerships/eshkol/' => 'http://www.jewishagency.org/eshkol', 
      'english/partnerships/hadera/' => 'http://www.jewishagency.org/hadera', 
      'english/partnerships/kfarsaba/' => 'http://www.jewishagency.org/kfarsaba', 
      'english/partnerships/kinneret/' => 'http://www.jewishagency.org/kinneret', 
      'english/partnerships/kiryatmalachi/' => 'http://www.jewishagency.org/kiryatmalachi', 
      'english/partnerships/modiin/' => 'http://www.jewishagency.org/modiin', 
      'english/partnerships/ofakim/' => 'http://www.jewishagency.org/ofakim', 
      'english/partnerships/roshhaayin/' => 'http://www.jewishagency.org/roshhaayin', 
      'english/partnerships/tzahar/' => 'http://www.jewishagency.org/tzahar', 
      'english/partnerships/westerngalilee/' => 'http://www.jewishagency.org/westerngalilee', 
      'english/partnerships/yoav/' => 'http://www.jewishagency.org/yoav', 
      'english/partnerships/yokneam/' => 'http://www.jewishagency.org/yokneam', 
      'hebrew/partnerships/arava/limmud/' => 'http://www.jewishagency.org/he/limmudarava', 
      'hebrew/partnerships/arava/' => 'http://www.jewishagency.org/he/arava', 
      'hebrew/partnerships/beersheva/' => 'http://www.jewishagency.org/he/beersheva', 
      'hebrew/partnerships/beitshean/' => 'http://www.jewishagency.org/he/beitshean', 
      'hebrew/partnerships/beitshemesh/' => 'http://www.jewishagency.org/he/beitshemesh', 
      'hebrew/partnerships/carmiel/' => 'http://www.jewishagency.org/he/carmiel', 
      'hebrew/partnerships/centralgalilee/' => 'http://www.jewishagency.org/he/centralgalilee', 
      'hebrew/partnerships/eshkol/' => 'http://www.jewishagency.org/he/partnership2gether', 
      'hebrew/partnerships/kfarsaba/' => 'http://www.jewishagency.org/he/kfarsaba', 
      'hebrew/partnerships/kinneret/' => 'http://www.jewishagency.org/he/kinneret', 
      'hebrew/partnerships/roshhaayin/' => 'http://www.jewishagency.org/he/partnership2gether', 
      'hebrew/' => 'http://www.jewishagency.org/he/partnership2gether',  
      'english/israelschools/' => 'http://www.jewishagency.org/partnership2gether/program/5091');
  if (isset($redirect_array[$location])) {
    header("Location: " . $redirect_array[$location]);
  } else {
    header("Location: http://www.jewishagency.org/partnership2gether");
  }
  die();
}

if (isset($_GET['server_check'])) {
    print '<pre>';
    print_r($_SERVER);
    print '</pre>';
}
?>