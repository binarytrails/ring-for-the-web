# [XPCOM](https://developer.mozilla.org/en-US/docs/Mozilla/Tech/XPCOM)

## Getting started

Name your extension and create a directory with that name under the /mozilla/extensions/ directory.

Use only lowercase letters.

[Creating custom Firefox extensions with the Mozilla build system](https://developer.mozilla.org/en-US/Add-ons/Creating_Custom_Firefox_Extensions_with_the_Mozilla_Build_System)

### Compiling

I followed [this](http://www.iosart.com/firefox/xpcom/) to build the xpcom-sample. During *make* the Gecko SDK aka XULRunner SDK didn't worked. It seems that using the XULRunner from [Mozilla Web](https://developer.mozilla.org/en-US/docs/Mozilla/Gecko/Gecko_SDK) has tons of issues and using the [Mozilla FTP 1.7](http://ftp.mozilla.org/pub/mozilla/releases/mozilla1.7/) or 1.7.3 is only compatible with i386.

## Compatibility

> In August 2015, Mozilla announced that the use of [XUL]((https://developer.mozilla.org/en-US/docs/Archive/Mozilla/XULRunner) for creating Firefox add-ons would be deprecated in the future in favour of WebExtensions.

### Web browser engine

> XUL has no formal specification and does not inter-operate with non-Gecko implementations. -- [Wikipedia](https://en.wikipedia.org/wiki/XUL)

[Gecko vs WebKit](https://support.mozilla.org/en-US/questions/1052733)

