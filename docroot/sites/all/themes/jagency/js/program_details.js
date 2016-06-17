/*Drupal.ACDB.prototype.customSearch = function (searchString) {
  jQuery(document).ready(function($) {
    $("#edit-field-main-category-und").change(function() {
      searchString = searchString + "/" + $("#edit-field-main-category-und option:selected").val();
      //$("#edit-field-program-und-0-target-id-autocomplete").val("/entityreference/autocomplete/single/field_program/node/program_details/" + CatVALUE);
    }).change();
    return this.search(searchString);
  });
};

Drupal.jsAC.prototype.populatePopup = function () {
  // Show popup
  if (this.popup) {
    $(this.popup).remove();
  }
  this.selected = false;
  this.popup = document.createElement('div');
  this.popup.id = 'autocomplete';
  this.popup.owner = this;
  $(this.popup).css({
    marginTop: this.input.offsetHeight +'px',
    width: (this.input.offsetWidth - 4) +'px',
    display: 'none'
  });
  $(this.input).before(this.popup);

  // Do search
  this.db.owner = this;
  if (this.input.id == 'edit-field-program-und-0-target-id') {
    this.db.customSearch(this.input.value);
  } else {
    this.db.search(this.input.value);
  }
}

Drupal.behaviors.rebindAutocomplete = function(context) {
    // Unbind the behaviors to prevent multiple search handlers
    $("#edit-field-program-und-0-target-id-autocomplete").unbind('keydown').unbind('keyup').unbind('blur').removeClass('autocomplete-processed');
    // Rebind autocompletion with the new code
    Drupal.behaviors.autocomplete(context);
}
*/
jQuery(document).ready(function() {
  if (typeof($) == "undefined") {
    $ = jQuery;
  }
  var autocompletePath = jQuery('#edit-field-program-und-0-target-id-autocomplete').val();
  jQuery('#edit-field-main-category-und').change(function() {
    var category = jQuery(this).val();
    var newURL = autocompletePath.replace('NULL', category);                                                                      
    // Trick Drupal into rebinding the autocomplete behavior.                 
    jQuery('#edit-field-program-und-0-target-id-autocomplete').val(newURL).removeClass('autocomplete-processed');
    jQuery('#edit-field-program-und-0-target-id').unbind().val('');                           
    Drupal.behaviors.autocomplete.attach(document);
    return false;                                                             
  });

  jQuery(".widget_program_tags_checkbox .checkbox_div label, .widget_program_tags_checkbox .checkbox_div input[type='checkbox']").click(function(event) {
      event.preventDefault();
      var SelectedID = $('#' + $(this).attr('for')).val();
      if($("#edit-field-program-tags-und option[value='" + SelectedID + "']:selected").length) {
        $("#edit-field-program-tags-und option[value='" + SelectedID + "']").attr("selected", false).trigger('change');
      } else {
        $("#edit-field-program-tags-und option[value='" + SelectedID + "']").attr("selected", "selected").trigger('change');
      }
      $(this).toggleClass("active");
  });
});