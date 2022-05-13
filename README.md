readline으로 받아온 command 토큰화 전 에러 처리
1. quote, double quote가 홀수인 경우
2. redirect 다음에 변수 없는 경우
3. "-" 다음에 문자 없는 경우
4. 추후 발견하면 추가

command 토큰화 기준
1. quote, double quote가 나오면 짝을 찾아 토큰화
2. >, < 기호 발견 시 single인지 double인지 뒷 문자도 확인하고 토큰화
3. 기준 문자: |, <, >, <<, >>, ', "
4. 기준 문자 이외에는 space 기준으로 파싱

토큰 트리화 기준

PIPE ->         left: CMD,                   right: PIPE
CMD ->          left: REDIRECTS,             right: SIMPLECMD
SIMPLECMD ->    left: file_path,             right: ARGV
REDIRECTS ->    left: REDIRECT or REDIRECTS  right: REDIRECT or REDIRECTS
REDIRECT ->     left: type,                  right: file_name
