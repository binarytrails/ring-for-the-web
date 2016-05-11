var RingNacl = null;  // Global application object.

function moduleDidLoad() {
    RingNacl = document.getElementById('RingNacl');
    if (RingNacl == null) {
        alert('RingNacl did not load');
    }
    else {
        RingNacl.postMessage('hello from the binary');
    }
    RingNacl.addEventListener('message', handleMessage, false);
}
function handleMessage(message_event) {
   alert(message_event.data);
}

chrome.browserAction.onClicked.addListener(moduleDidLoad);
document.getElementById('listener').addEventListener('load', moduleDidLoad, true);
