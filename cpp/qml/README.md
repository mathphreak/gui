# GUIs/c++/QML

Made a Qt Quick Controls 2 Application with Qt Creator.
Style: Default.

Things that still don't work:
- The ListView is empty and I don't know why.
- Ideally the UI would pass along events to the actual C++ application rather than handling them internally. As such, this is an unrealistic example.

Qt Creator crash count: 2

## Metrics

- Lines of code: **280** (counted naïvely, including all the GUI builder generated stuff)
- Distinct API calls: **12** (decided rather arbitrarily)
- Launch time: (measured badly on a system under normal load with /misc/MeasureTiming.ahk)
  - Compiled and launched from Qt Creator: **3.130288 s**
- Idle RAM usage: **36,760 K** (measured by Windows, compiled in release mode)
- Executable size: **21.5 KB** (measured by Windows, compiled in release mode)
