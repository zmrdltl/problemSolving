function intToString(maxTime) {
  let tmp = "";
  const hour = maxTime / 3600;
  if (hour < 10) tmp += "0";
  tmp += hour.toString() + ":";
  maxTime %= 3600;

  const minute = maxTime / 60;
  if (minute < 10) tmp += "0";
  tmp += minute.toString() + ":";
  maxTime %= 60;

  const sec = maxTime;
  if (sec < 10) tmp += "0";
  tmp += sec.toString();
  return tmp;
}

function solution(play_time, adv_time, logs) {
  const logStartSec = [];
  const logEndSec = [];
  const totalTime = new Array(400000);
  let maxTime = 0;
  let playTime = play_time.split(":");
  let advTime = adv_time.split(":");
  const playTimeSec =
    parseInt(playTime[2]) +
    parseInt(playTime[1]) * 60 +
    parseInt(playTime[0]) * 3600;
  const advTimeSec =
    parseInt(advTime[2]) +
    parseInt(advTime[1]) * 60 +
    parseInt(advTime[0]) * 3600;

  for (let i = 0; i < logs.length; i++) {
    logs[i] = logs[i].split("-");

    let logStart = logs[i][0].split(":");
    let logEnd = logs[i][1].split(":");

    const startSec =
      parseInt(logStart[2]) +
      parseInt(logStart[1]) * 60 +
      parseInt(logStart[0]) * 3600;
    const endSec =
      parseInt(logEnd[2]) +
      parseInt(logEnd[1]) * 60 +
      parseInt(logEnd[0]) * 3600;

    logStartSec.push(startSec);
    logEndSec.push(endSec);
  }
  for (let i = 0; i < logs.length; i++) {
    totalTime[logStartSec[i]] = totalTime[logStartSec[i]] + 1;
    totalTime[logEndSec[i]] = totalTime[logEndSec[i]] - 1;
  }
  for (let i = 1; i < playTimeSec - 1; i++) {
    totalTime[i] = totalTime[i] + totalTime[i - 1];
  }
  for (let i = 1; i < playTimeSec - 1; i++) {
    totalTime[i] = totalTime[i] + totalTime[i - 1];
  }
  for (let i = advTimeSec - 1; i < playTimeSec - 1; i++) {
    if (i >= advTimeSec)
      maxTime = Math.max(maxTime, totalTime[i] - totalTime[i - advTimeSec]);
    else maxTime = Math.max(maxTime, totalTime[i]);
  }
  console.log(maxTime);
  return intToString(maxTime);
}
