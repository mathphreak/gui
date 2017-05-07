const electron = require('electron');

// Keep a global reference of the window object, if you don't, the window will
// be closed automatically when the javascript object is GCed.
let mainWindow = null;

electron.ipcMain.on('text', (event, arg) => {
  console.log('Button Pressed. Entered text: ' + arg);
});

electron.ipcMain.on('combo', (event, arg) => {
  console.log('Combo Box Changed. Selected item: ' + arg);
});

electron.ipcMain.on('checkbox', (event, arg) => {
  console.log('Check box ' + arg);
});

electron.ipcMain.on('radio', (event, arg) => {
  console.log('Radio ' + arg + ' checked');
});

electron.ipcMain.on('slider', (event, arg) => {
  console.log('Slider slid to ' + arg);
});

electron.ipcMain.on('spinner', (event, arg) => {
  console.log('Spinner spun to ' + arg);
});

// Quit when all windows are closed. Even on OS X.
electron.app.on('window-all-closed', () => electron.app.quit());

// This method will be called when Electron has done everything
// initialization and ready for creating browser windows.
electron.app.on('ready', () => {
  // Create the browser window.
  mainWindow = new electron.BrowserWindow({width: 800, height: 600, show: false});

  const url = `file://${__dirname}/index.html`;

  // And load the index.html of the app.
  mainWindow.loadURL(url);

  mainWindow.show();

  // Emitted when the window is closed.
  mainWindow.on('closed', () => {
    // Dereference the window object, usually you would store windows
    // in an array if your app supports multi windows, this === the time
    // when you should delete the corresponding element.
    mainWindow = null;
  });
});
