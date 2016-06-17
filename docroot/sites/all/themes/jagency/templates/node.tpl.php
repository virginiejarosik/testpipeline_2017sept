<?php
$item = menu_get_item();
if (isset($item['map'][0]) && $item['map'][0] == 'node' && count($item['map']) == 1) {
  header("HTTP/1.0 410 Gone");
  print '<script>location.href = "' . url('', array('absolute' => true)) . '";</script>';
  die();
}

$_template_file = realpath(dirname(__FILE__) . '/node/' . $node -> type . '/node-' . $node -> type . '-' . $view_mode . '.tpl.php');
if (!$_template_file) {
  $_template_file = realpath(dirname(__FILE__) . '/node/' . 'node-default-' . $view_mode . '.tpl.php');
  if (!$_template_file) {
    $_template_file = realpath(dirname(__FILE__) . '/node/' . 'node-default-full.tpl.php');
  }
}
include $_template_file;
