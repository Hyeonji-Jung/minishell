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

![image](https://user-images.githubusercontent.com/67726356/169008976-4023d913-135b-482f-a593-8db26e482010.png)

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
    - [v] pipe 기준
    - [v] redirects(<, >, <<, >>) 기준
    - [] quote, double quote 기준 (quote의 경우 환경변수도 해석해야 함)
    - [v] 기준 문자 이외에는 space 기준으로 토큰화
  - [] tokenization 이후 에러 처리
    - [] redirects token 이후 문자열 토큰이 없는 경우
    - [] pipe 토큰 이후 simple cmd 토큰 없는 경우
    - [] simple cmd && 존재하지 않는 빌트인인 경우
  - [v] 트리로 만들기
    - [v] 트리화 기준에 따라 트리 만들기
- [] execute
  - [] 트리 순회하며 명령어 실행하기
    - [] 명령어 기다릴 때 프롬프트 보여야 함
    - [] 최초 자식 process 생성
    - [] 부모 프로세스에서 pipe, cmd node에 따라 fork 및 pipe 처리 잘 해주어야 함
    - [] builtin 처리
      - [] echo -n
      - [] cd 상대경로/절대경로
      - [v] pwd
      - [v] export
      - [v] unset
      - [v] env
      - [v] exit
    - [] signal 처리
      - [] ctrl-C
      - [] ctrl-D
      - [] ctrl-\
    - [] redirects 처리
      - [] 존재하지 않는 파일 열거나 읽는 경우 예외 처리
      - [] 파일 생성 및 읽기 잘못된 경우 예외 처리 등등
    - [v] 환경변수($) 처리
  - [] 마지막 자식 프로세스 종료 후 모든 메모리 해제 등 깔끔한 마무리
  - [v] 이전 명령어 history 조회
