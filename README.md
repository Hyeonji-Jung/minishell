readline으로 받아온 command 토큰화 전 에러 처리

1. quote, double quote가 홀수인 경우
2. "-" 다음에 문자 없는 경우
3. 추후 발견하면 추가

+) redirect 다음에 변수 없는 경우 -> 이건 토큰 쪼개고 나서 검사해야 함(space 여러 개 나와도 작동해야 하니까)

<br/>

command 토큰화 기준

1. quote, double quote가 나오면 짝을 찾아 토큰화
2. >, < 기호 발견 시 single인지 double인지 뒷 문자도 확인하고 토큰화
3. 기준 문자: |, <, >, <<, >>, ', "
4. 기준 문자 이외에는 space 기준으로 파싱

<br/>

토큰 트리화 기준

PIPE ->         left: CMD,                   right: PIPE
CMD ->          left: REDIRECTS,             right: SIMPLECMD
SIMPLECMD ->    left: file_path,             right: ARGV
REDIRECTS ->    left: REDIRECT or REDIRECTS  right: REDIRECT or REDIRECTS
REDIRECT ->     left: type,                  right: file_name

<br/>

기능 구현 목록
- [] parsing
  - [] parsing 전 에러 처리
    - [] quote, double quote가 홀수인 경우
    - [] - 다음에 문자 없는 경우
  - [] tokenization
    - [] pipe 기준
    - [] redirects(<, >, <<, >>) 기준
    - [] quote, double quote 기준
    - [] 기준 문자 이외에는 space 기준으로 토큰화
  - [] tokenization 이후 에러 처리
    - [] 
