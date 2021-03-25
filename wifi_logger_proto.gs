// https://developers.google.com/adwords/scripts/docs/examples/spreadsheetapp
// gogle script file to upload data from CSL sensor system to google sheets

var SS = SpreadsheetApp.openById('16Ovmz_tTXF4VXYmIKxvItBF5CF8OK0dP7R_-emSp2eg');    //Enter Your Sheet ID Got From Sheet URL Link
var str = "waiting";

function doPost(e) {

  var parsedData;

  try {
    parsedData = JSON.parse(e.postData.contents);
  }
  catch (f) {
    return ContentService.createTextOutput("Error in parsing request body: " + f.message);
  }

  if (parsedData !== undefined) {

    switch (parsedData.command) {
      case "appendRow":
        var tmp = SS.getSheetByName(parsedData.sheet_name);
        var dataArr = parsedData.values.split(","); // get the values and split them into an array
        var d = new Date(); // get current datetime
        dformat = [d.getFullYear(), d.getMonth() + 1, d.getDate()].join('/') + ' ' + // convert to simple format yyyy/mm/dd hh:mm:ss
          [d.getHours(), d.getMinutes(), d.getSeconds()].join(':');

        dataArr.unshift(dformat); // add the system datetime to beginning of array
        tmp.appendRow(dataArr); // add row to gsheet 

        str = "Success";
        SpreadsheetApp.flush();
        break;
    }
    return ContentService.createTextOutput(str);
  } // endif (parsedData !== undefined)

  else {
    return ContentService.createTextOutput("Error! Request body empty or in incorrect format.");
  }
}

function doGet(e) {
  return ContentService.createTextOutput(str);
  // var val = e.parameter.value;
  // var cal = e.parameter.cal;
  // var read = e.parameter.read;

  // if (cal !== undefined) {
  //   return ContentService.createTextOutput(GetEventsOneWeek());
  // }

  // if (read !== undefined) {
  //   var now = Utilities.formatDate(new Date(), "EST", "yyyy-MM-dd'T'hh:mm a'Z'").slice(11, 19);
  //   //sheet.getRange('D1').setValue(now);
  //   //var count = (sheet.getRange('C1').getValue()) + 1;
  //   sheet.getRange('C1').setValue(count);
  //   return ContentService.createTextOutput(sheet.getRange('A1').getValue());
  // }

  // if (e.parameter.value === undefined)
  //   return ContentService.createTextOutput("No value passed as argument to script Url.");

  // var range = sheet.getRange('A1');
  // var retval = range.setValue(val).getValue();
  // var now = Utilities.formatDate(new Date(), "EST", "yyyy-MM-dd'T'hh:mm a'Z'").slice(11, 19);
  // //  sheet.getRange('B1').setValue(now);
  // sheet.getRange('B1').setValue("Humidity");
  // //sheet.getRange('C1').setValue('0');

  // if (retval == e.parameter.value)
  //   return ContentService.createTextOutput("Successfully wrote: " + e.parameter.value + "\ninto spreadsheet.");
  // else
  //   return ContentService.createTextOutput("Unable to write into spreadsheet.\nCheck authentication and make sure the cursor is not on cell 'A1'." + retval + ' ' + e.parameter.value);
}
