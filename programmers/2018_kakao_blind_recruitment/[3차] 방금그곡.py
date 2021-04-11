def changeSong(melody):
    if 'A#' in melody: melody = melody.replace('A#', 'a')
    if 'C#' in melody: melody = melody.replace('C#', 'c')
    if 'D#' in melody: melody = melody.replace('D#', 'd')
    if 'F#' in melody: melody = melody.replace('F#', 'f')
    if 'G#' in melody: melody = melody.replace('G#', 'g')
    return melody

def solution(m, musicinfos):
    m = changeSong(m)
    answer = ('(None)', None)
    for info in musicinfos:
        start, end, title, melody = info.split(',')
        startHour, startMin, endHour, endMin = map(int, start.split(':') + end.split(':'))
        time = 60 * (endHour-startHour) + (endMin-startMin)
        melody = changeSong(melody)
        playedTime = (melody*time)[:time]
        if m in playedTime:
            if (answer[1] == None) or (time > answer[1]):
                answer = (title, time)
    return answer[0]