<?php
//add folders in which the subsites reside to this array
$sites = array(); 
if (is_file(DRUPAL_ROOT . '/sites/default/files/domains.txt')) {
  $sites = unserialize(file_get_contents(DRUPAL_ROOT . '/sites/default/files/domains.txt'));//array('ru', 'he');
}
$request = explode('/', trim($_SERVER['REQUEST_URI'], '/'));
if (sizeof($request) && preg_match('/^\b' . implode('\b|\b', $sites) . '\b$/i', $request[0], $matches)) {
  //set the appropriate HTTP_HOST to trick Domain Access
  $site = $matches[0];
  if (substr($_SERVER['REQUEST_URI'], 0, strlen('/' . $site)) == '/' . $site) {
    $_SERVER['REQUEST_URI'] = substr($_SERVER['REQUEST_URI'], strlen('/' . $site), strlen($_SERVER['REQUEST_URI']));
  }
  $_SERVER['ORIGINAL_HTTP_HOST'] = $_SERVER['HTTP_HOST'];
  $_SERVER['HTTP_HOST'] = $site . '.' . $_SERVER['HTTP_HOST'];

  //rebuild the Q
  if (!empty($_GET['q'])) {
    $q = implode('/', $request);

    if (($pos = strpos($q, '?')) !== FALSE) {
      $q = substr($q, 0, $pos);
    }

    $size = strlen($site);

    $_GET['q'] = ltrim(substr($q, $size), '/');
    $HTTP_GET_VARS['q'] = $q;
  }
  //used to set the correct $base_url in settings.php
  global $da_site;
  $da_site = strtolower($site);
}
