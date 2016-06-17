jQuery(document).ready(function ($) {
  $("#search").val(Drupal.t("Search"))
  $("#search").focus(function() {
    if ($(this).val() == Drupal.t("Search")) {
      $(this).val("")
    }
  });
  $("#search").blur(function() {
    if ($(this).val() == "") {
      $(this).val(Drupal.t("Search"))
    }
  });
});
