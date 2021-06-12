# ft_printf

[##_Image|kage@bFwTE3/btq5VxSOBeF/vDlJUP8x5lxspfoNdDCzqk/img.png|alignCenter|data-origin-width="1238" data-origin-height="1716" width="527" height="730" data-ke-mobilestyle="widthOrigin"|||_##]

## Summary && Introduction

-   `printf` 함수를 똑같이 구현하라.
-   차후 프로젝트에서 사용 될 것이다.
-   **가변인자**에 대한 사용법을 배운다.
-   **성공적인 ft\_printf 의 핵심은 구조화 및 확장 가능한 코드이다.**

## Common Instructions

-   Norm check를 준수하여 코드를 작성하라. (보너스 파트 포함) - 아닐시 0점부여
-   함수 작성시 segmentation fault, bus error, double free 등등의 갑작스런 종료에 주의해라. - 아닐시 0점 부여
-   메모리 누수는 허용되지 않는다. 모든 할당된 힙 메모리에 대하여 적절한 free를 해야한다. - 아닐시 0점 부여
-   relink 되지 않은 Makefile을 작성하여 제출하라. 컴파일은`-Wall -Wextra -Werror`플래그를 사용하여 컴파일하게된다.
-   Makefile에는 `$(NAME)` `all` `clean` `fclean` `re`를 포함하여야 한다.
-   이 프로젝트에서 libft를 사용한다면, 소스파일과 관련 makefile을 함께 libft폴더에 넣어야한다. 그리고 ft\_printf의 makefile은 libft를 컴파일 한 후에 ft\_printf프로젝트를 컴파일하여야 한다.

## Mandatory part

[##_Image|kage@bGTlMD/btq5REkHHCI/6dobcvws1JJrvP4FFIENM0/img.png|alignCenter|data-origin-width="1221" data-origin-height="336" data-ke-mobilestyle="widthOrigin"|||_##]

-   ft\_printf의 원형은 반드시 `int ft_printf(const char *, ...)`로해라.
-   C표준 라이브러리(libc)의 printf 함수를 recode해야한다.
-   원본 printf처럼 buffer 관리를 해서는 안된다.
-   다음과 같은 서식문자(conversion)를 다뤄야한다. : `cspdiuxX%`
-   모든 서식문자에서 `-0.*`플래그와 **최소 필드 너비**(minimum field width)을 다뤄야한다.
-   원래의 printf 함수와 비교될것이다.
-   `ar` 커맨드를 사용하여 라이브러리를 만들어라. `libtool`은 금지되어있다.

##   
