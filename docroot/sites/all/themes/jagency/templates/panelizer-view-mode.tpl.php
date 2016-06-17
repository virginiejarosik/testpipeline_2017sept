<?php
$type = $variables['element']['#entity_view_mode']['bundle'];
$view_mode = $variables['element']['#entity_view_mode']['view_mode'];
$_template_file = realpath(dirname(__FILE__) . '/panelizer/' . $type . '/panelizer-' . $type . '-' . $view_mode . '.tpl.php');
if (!$_template_file) {
  $_template_file = realpath(dirname(__FILE__) . '/panelizer/' . 'panelizer-default-' . $view_mode . '.tpl.php');
  if (!$_template_file) {
    $_template_file = realpath(dirname(__FILE__) . '/panelizer/' . 'panelizer-default.tpl.php');
  }
}
include $_template_file;
