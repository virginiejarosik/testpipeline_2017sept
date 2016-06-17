<li id="<?php print $node->nid; ?>"> 
  <span class="num"></span>
  <?php 
    if(isset($content['field_button_reference'])) {
      print l($title, 'node/' . render($content['field_button_reference']), array('attributes' => array('title' => $title))); 
    } else {
      print '<span class="withoutlink">' . $title . '</span>';
    }
    ?>
  <p><?php print render($content['body']); ?></p>
</li>