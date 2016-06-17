
// Start - Linked Projects Popup

function studentLifePopup() {
    $("#studentLifePopup").dialog({
        bgiframe: true,
        width: 777,
        //height: 350,
        modal: true,
        autoOpen: true,
        draggable: false,
        dialogClass: 'studentLifePopupFrame'
    });
    $('div[class="ui-dialog-titlebar ui-widget-header ui-corner-all ui-helper-clearfix"]').hide();
    $("#studentLifePopup").dialog("open");

}

// End - Linked Projects Popup


function closedialog() {
    $('.ui-dialog-titlebar-close').click();
}

