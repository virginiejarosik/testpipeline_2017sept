<?php
  $faf_photos_html = "";
  $light_box_class = "target='_blank'";
  $default_class = "faf_imagebox";
  $faf_image_columns = variable_get("faf_image_columns");
  $faf_image_class = variable_get("faf_image_class");
  $faf_image_lightbox = variable_get("faf_image_lightbox");
  if ($faf_image_lightbox) {
    $light_box_class = "rel='lightbox[" . $album_id . "]'";
  }
  if ($faf_image_class) {
    $default_class = $faf_image_class;
  }
  $image_counter = 1;
  $faf_photos_html .= '<ul class="Facebook_album">';
  foreach ($photos_array as $key) {
    $faf_photos_html .= "<li><a href='" . $key->source . "' $light_box_class><img src = '" . $key->picture . "' class='" . $default_class . "'></a></li>";
    if ($faf_image_columns && $image_counter) {
      if ($image_counter % $faf_image_columns == 0) {
        $faf_photos_html = "<li>" . $faf_photos_html . "</li>";
      }
    }
    $image_counter++;
  }
  $faf_photos_html .= '</ul>';
  return $faf_photos_html;
