var NaclCorrectionModule = null;  // Global application object.

function moduleDidLoad() {
  NaclCorrectionModule = document.getElementById('hello_tutorial');
  if (NaclCorrectionModule == null) {
    console.log("NaclCorrectionModule did not load");
  }
  else {
    console.log("Ayy NaclCorrectionModule did load");
  }
  NaclCorrectionModule.addEventListener('message', handleMessage, false);
}

function handleMessage(message_event) {
  alert(message_event.data);
}

chrome.browserAction.onClicked.addListener(moduleDidLoad);
document.getElementById('listener').addEventListener('load', moduleDidLoad, true);
