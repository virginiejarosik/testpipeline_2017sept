<?php
function d() {
  $placeholder = "\n==========================\n";
  $plains_array = Array('boolean', 'integer', 'double', 'string');
  $args = func_get_args();
  $btrace = debug_backtrace();
  if (isset($args[0]) && is_bool($args[0])) {
    $all = $args[0];
    unset($args[0]);
  } else
    $all = FALSE;

  if ($all == FALSE) {
    $rbt = @ Array($btrace[1]);
  } else {
    $rbt = array_reverse($btrace);
  }

  foreach ($rbt as $index => $data) {
    $tmp_args = Array();
    if (is_array($data))
      foreach ($data['args'] as $idx => $arg) {
        $atype = gettype($arg);
        if (in_array($atype, $plains_array)) {
          $arg_text = $arg;
          if (is_string($arg))
            $arg_text = '"' . $arg_text . '"';
          if (is_bool($arg))
            $arg_text = ($arg ? 'TRUE' : 'FALSE');
        } else {
          $arg_text = $atype . '#' . count($arg);
        }
        $tmp_args[$idx] = $arg_text;
      }
    $args_string = implode(', ', $tmp_args);
    $stack[$index] = basename($data['file']) . ':' . $data['line'] . ' -- ' . $data['function'] . '(' . $args_string . ')';
  }
  echo '<pre style="direction:ltr;">';
  echo "Trace:" . $placeholder;
  print_r($stack);
  echo $placeholder . 'Arguments' . $placeholder;
  print_r($args);
  die();
}

//silent debug function
function _dd() {
  $filename = 'dump.txt';
  $args = func_get_args();
  if (count($args) <= 0) {
    $h = fopen($filename, 'wb');
    fclose($h);
    return;
  }
  $h = fopen($filename, 'a+b');
  if (is_resource($h)) {
    ob_start();
    $placeholder = "\n==============================================================================\n";
    $plains_array = Array('boolean', 'integer', 'double', 'string');
    $btrace = debug_backtrace();
    if (is_bool($args[0])) {
      $all = $args[0];
      unset($args[0]);
    } else
      $all = FALSE;
    if ($all == FALSE)
      $rbt = Array($btrace[1]);
    else
      $rbt = array_reverse($btrace);
    foreach ($rbt as $index => $data) {
      $tmp_args = Array();
      $stack = Array();
      if (isset($data['args']))
        foreach ($data['args'] as $idx => $arg) {
          $atype = gettype($arg);
          if (in_array($atype, $plains_array)) {
            $arg_text = $arg;
            if (is_string($arg))
              $arg_text = '"' . $arg_text . '"';
            if (is_bool($arg))
              $arg_text = ($arg ? 'TRUE' : 'FALSE');
          } else {
            $arg_text = $atype . '#' . count($arg);
          }
          $tmp_args[$idx] = $arg_text;
        }
      $args_string = implode(', ', $tmp_args);
      $stack[$index] = basename($data['file']) . ':' . $data['line'] . ' -- ' . $data['function'] . '(' . $args_string . ')';
    }
    echo '<pre>';
    echo "Trace:" . $placeholder;
    print_r($stack);
    echo $placeholder . 'Arguments' . $placeholder;
    print_r($args);
    $buf = ob_get_clean();
    $buf .= "\n---------------------------------------------------------------------------------\n";
    $count = fwrite($h, $buf . "\r\n\r\n");
    fclose($h);
  }
}
?>