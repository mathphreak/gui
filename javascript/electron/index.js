/* eslint-env browser */
const electron = require('electron');

document.addEventListener('click', evt => {
  if (evt.target.id === 'textButton') {
    electron.ipcRenderer.send('text', document.querySelector('input[type=text]').value);
  }
});

document.addEventListener('change', evt => {
  if (evt.target.id === 'combo') {
    const select = evt.target;
    electron.ipcRenderer.send('combo', select.options[select.selectedIndex].value);
  } else if (evt.target.type === 'checkbox') {
    electron.ipcRenderer.send('checkbox', evt.target.checked ? 'checked' : 'unchecked');
  } else if (evt.target.type === 'radio') {
    electron.ipcRenderer.send('radio', evt.target.value);
  } else if (evt.target.type === 'range') {
    electron.ipcRenderer.send('slider', evt.target.value);
  } else if (evt.target.type === 'number') {
    electron.ipcRenderer.send('spinner', evt.target.value);
  }
});
