/* eslint-env browser */
function ping(path, text) {
  const url = path + '?text=' + encodeURIComponent(text);
  const oReq = new XMLHttpRequest();
  oReq.open('POST', url);
  oReq.send();
}

document.addEventListener('click', evt => {
  if (evt.target.id === 'textButton') {
    ping('/text', document.querySelector('input[type=text]').value);
  }
});

document.addEventListener('change', evt => {
  if (evt.target.id === 'combo') {
    const select = evt.target;
    ping('/combo', select.options[select.selectedIndex].value);
  } else if (evt.target.type === 'checkbox') {
    ping('/checkbox', evt.target.checked ? 'checked' : 'unchecked');
  } else if (evt.target.type === 'radio') {
    ping('/radio', evt.target.value);
  } else if (evt.target.type === 'range') {
    ping('/slider', evt.target.value);
  } else if (evt.target.type === 'number') {
    ping('/spinner', evt.target.value);
  }
});
