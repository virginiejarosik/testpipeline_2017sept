<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 */
   // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
?>

  <div class="col480 contactBox">
  <h3><?php print $title; ?></h3>
      <?php
        // Print out the main part of the form.
        // Feel free to break this up and move the pieces within the array.

        // Always print out the entire $form. This renders the remaining pieces of the
        // form that haven't yet been rendered above.
        print drupal_render($content);
      ?>
    </div>
    
