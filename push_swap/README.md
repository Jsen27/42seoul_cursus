# **Push Swap**

### ***Summary: This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.***

*요약: 이번 과제에서는 스택에 있는 데이터를 한정된 명령어를 이용하여 최대한 적은 횟수 내에 정렬하는 것을 목표로 합니다. 성공하기 위해서는 다양한 정렬 알고리즘을 조작해 보고, 최적화된 데이터 정렬에 가장 적합한 알고리즘을 선택하여야 합니다.*

---

[![Notion](https://img.shields.io/badge/Notion-Click%20Here-blue?style=for-the-badge&logo=notion)](https://jsen27.notion.site/push_swap-76f142d2e7794b02a5cfbfb4284c73ec?pvs=4)

If you want to know about the assignment, check my notion.

---

# **Chapter 1**

## **Foreword**

- `C`
    
    `#include <stdio.h>int main(void)
    {
    		printf("hello, world\n");
    		return 0;
    }`
    
- `ASM`
    
    `cseg segment
    assume cs:cseg, ds:cseg
    org 100h
    main proc
    jmp debut
    mess db 'Hello world!$'
    debut:
    mov dx, offset mess
    mov ah, 9
    int 21h
    ret
    main endp
    cseg ends
    end main`
    
- `LOLCODE`
    
    `HAI
    CAN HAS STDIO?
    VISIBLE "HELLO WORLD!"
    KTHXBYE`
    
- `PHP`
    
    `<?php
      echo "Hello world!";
    ?>`
    
- `BrainFuck`
    
    `++++++++++[>+++++++>++++++++++>+++>+<<<<-]
    >++.>+.+++++++..+++.>++.
    <<+++++++++++++++.>.+++.------.--------.>+.>.`
    
- `C#`
    
    `using System;
    
    public class HelloWorld {
    		public static void Main () {
    				Console.WriteLine("Hello world!");
    		}
    }`
    
- `HTML5`
    
    `<!DOCTYPE html><html>
      <head>
        <meta charset="utf-8" />
        <title>Hello world !</title>
      </head>
      <body>
        <p>Hello World !</p>
      </body>
    </html>`
    
- `YASL`
    
    `"Hello world!"
    print`
    
- `OCaml`
    
    `let main () =
    	print_endline "Hello world !"let _ = main ()`
    

# **Chapter 2**

## **Introduction**

### ***The `Push_swap` project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.***

`Push_swap` 프로젝트는 아주 간단하고 꽤나 중요한 알고리즘 프로젝트입니다. 이 프로젝트에서는 데이터를 정렬하여야 해요. 과제에서는 정렬해야 하는 int 값들과 두 개의 스택, 그리고 이 스택을 조작하는 명령어 집합이 주어집니다.

### ***Your goal ? Write a program in `C` called `push_swap` which calculates and displays on the standard output the smallest program using `Push_swap` instruction language that sorts the integer arguments received.***

여러분의 목표는 `C`언어로 `Push_swap`이라는 프로그램을 작성하시는 겁니다. `Push_swap` 프로그램은 최소한의 `Push_swap` 명령어들을 이용하여 정수형 인자를 정렬하는 방법을 계산하고, 최종적으로 사용된 명령어들을 표준 출력해야 해요.

### ***Easy?***

쉬워보이죠?

### ***We’ll see about that...***

두고보세요...

# **Chapter 3**

## **Goals**

### ***To write a sorting algorithm is always a very important step in a coder’s life, because it is often the first encounter with the concept of [complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms).***

정렬 알고리즘을 작성하는 것은 코더의 삶에서도 꽤나 중요한 비중을 차지하는 부분입니다. 대개 **[복잡도](https://en.wikipedia.org/wiki/Analysis_of_algorithms)**의 개념을 여기서 처음 마주하게 되거든요.

### ***Sorting algorithms, and their complexities are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts because you’ll have to face them at one point.***

정렬 알고리즘과 복잡도는 기업 면접에서 자주 질문하는 문항이기도 합니다. 언젠가는 마주할 내용이기 때문에, 이번 기회에 개념을 잘 다지는 것도 좋은 방법이겠지요.

### ***The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially looking at the complexity of these basic algorithms.***

이번 과제의 목표는 엄격함, C언어의 사용과 기본적인 알고리즘의 사용입니다. 기본 알고리즘들의 복잡도에 대해 면밀히 살펴보세요.

### ***Sorting values is simple. To sort them the fastest way possible is less simple, especially because from one integers configuration to another, the most efficient sorting algorithm can differ.***

값을 정렬하는 건 꽤나 간단합니다만, 가능한 한 빠르게 정렬하는 것은 조금 복잡합니다. 어떤 정수 집합을 정렬하는지에 따라 최적의 알고리즘이 달라지거든요.

# **Chapter 4**

## **General Instructions**

### ***This project will only be corrected by actual human beings. You are therefore free to organize and name your files as you wish, although you need to respect some requirements listed below.***

이 프로젝트는 실제 인간에 의해서만 채점됩니다. 따라서, 파일의 이름이나 폴더 위치는 자유롭게 구성하세요. 다만, 아래에 나열된 필수 요건은 지켜주세요.

- ***The executable file must be named `push_swap`.***
    
    실행 파일명은 반드시 `push_swap` 이여야 합니다.
    
- ***You must submit a `Makefile`. That `Makefile` needs to compile the project and must contain the usual rules. It can only recompile the program if necessary.***
    
    `Makefile`을 함께 제출하셔야 합니다. `Makefile`은 프로젝트를 컴파일할 수 있어야 하고, 항상 작성하던 기본 룰을 포함하고 있어야 합니다. 또한, 필요한 경우에만 재컴파일하여야 합니다.
    
- ***If you are clever, you will use your library for this project, submit also your folder `libft` including its own `Makefile` at the root of your repository. Your `Makefile` will have to compile the library, and then compile your project.***
    
    현명하게 과제를 수행하고자 한다면, 여러분이 작성한 `libft`를 사용하는 것도 하나의 방법입니다. 이를 위해선, `libft`의 `Makefile`을 포함한 `libft` 폴더를 레포지토리의 루트 경로에 배치하세요. 프로젝트의 `Makefile`은 먼저 `libft`를 컴파일하고, 프로젝트를 컴파일하여야 합니다.
    
- ***Global variables are forbidden.***
    
    전역변수는 사용할 수 없습니다.
    
- ***Your project must be written in C in accordance with the Norm.***
    
    C언어를 사용하여 프로그램을 작성하여야 하며, `Norm` 규칙을 철저히 지켜야 합니다.
    
- ***You have to handle errors in a sensitive manner. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).***
    
    여러분은 반드시 오류를 세심하게 처리하셔야 합니다. 어떠한 이유 (Segmentation fault, bus error, double free 등) 에서도 프로그램이 예상치 못하게 종료되면 안 됩니다.
    
- ***Neither program can have any memory leaks.***
    
    프로그램에 메모리 누수가 발생하면 안 됩니다.
    
- ***Within your mandatory part you are allowed to use the following functions:***
    
    필수 파트에서는 다음과 같은 함수들의 사용이 허용됩니다 :
    
    - `write`
    - `read`
    - `malloc`
    - `free`
    - `exit`
- ***You can ask questions on the forum & Slack...***

게시판, 슬랙 등에서 자유롭게 질문하실 수 있습니다.

# **Chapter 5**

## **Mandatory part**

## **5.1 Game rules**

### **_The game is composed of 2 [stacks](https://en.wikipedia.org/wiki/Stack_(abstract*data_type)) named a and b.***

게임은 두 개의 [스택](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) a와 b를 가지고 진행됩니다.

- ***To start with:***
    
    시작 시점에서:
    
    - ***the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.***
        
        스택 a는 랜덤한 개수의 양의 정수들과 음의정수들을 포함하며, 값은 중복되지 않습니다.
        
    - ***b is empty***
        
        스택 b는 비어있습니다.
        
- ***The goal is to sort in ascending order numbers into stack a.***
    
    게임의 목표는 스택 a에 정수들을 오름차순으로 정렬하는 것입니다.
    
- ***To do this you have the following operations at your disposal:***
    
    여러분은 목표를 달성하기 위해서 다음과 같은 명령어를 사용하실 수 있어요:
    
    ### ***sa : `swap a` - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).***
    
    **sa** : `swap a` - 스택 a의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 a가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
    
    ### ***sb : `swap b` - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).***
    
    **sb** : `swap b` - 스택 b의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 b가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
    
    ### ***ss : `sa` and `sb` at the same time.***
    
    **ss** - `sa`와 `sb`를 동시에 수행합니다.
    
    ### ***pa : `push a` - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.***
    
    **pa** : `push a` - 스택 b의 top에 위치한 원소 한 개를 스택 a의 top으로 옮깁니다. 스택 b가 비어있을 경우에는 아무 동작도 하지 않습니다.
    
    ### ***pb : `push b` take the first element at the top of a and put it at the top of b. Do nothing if a is empty.***
    
    **pb** : `push b` - 스택 a의 top에 위치한 원소 한 개를 스택 b의 top으로 옮깁니다. 스택 a가 비어있을 경우에는 아무 동작도 하지 않습니다.
    
    ### ***ra : `rotate a` - shift up all elements of stack a by 1. The first element becomes the last one.***
    
    **ra** : `rotate a` - 스택 a의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
    
    ### ***rb : `rotate b` shift up all elements of stack b by 1. The first element becomes the last one.***
    
    **rb** : `rotate b` - 스택 b의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
    
    ### ***rr : `ra` and `rb` at the same time.***
    
    **rr** : `ra`와 `rb`를 동시에 수행합니다.
    
    ### ***rra : `reverse rotate a` - shift down all elements of stack a by 1. The last element becomes the first one.***
    
    **rra** : `reverse rotate a` - 스택 a의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
    
    ### ***rrb : `reverse rotate b` - shift down all elements of stack b by 1. The last element becomes the first one.***
    
    **rrb** : `reverse rotate b` - 스택 b의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
    
    ### ***rrr : `rra` and `rrb` at the same time.***
    
    **rrr** : `rra`와 `rrb`를 동시에 수행합니다.
    

## **5.2 Example**

### ***To illustrate the effect of some of these instructions, let’s sort a random list of integers.***

이 명령어들의 수행 결과를 자세히 알아보기 위해, 랜덤한 정수 배열을 정렬해 보겠습니다.

### ***In this example, we’ll consider that both stack are growing from the right.***

이번 예시에서는, 두 스택 a, b 모두 오른쪽으로 크기가 증가한다고 가정합시다.

- `---------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------`

### ***This example sort integers from a in 12 instructions. Can you do better ?***

이 예시는 스택 a의 정수들을 12개의 명령어를 사용하여 정렬합니다. 더 빠르게 정렬할 수 있으시겠어요?

## **5.3 The “push_swap” program**

- ***You have to write a program named `push_swap` which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).***
    
    여러분은 스택 a에 들어갈 정수의 목록을 인자값으로 받는 `push_swap` 프로그램을 작성해야 합니다. 첫 번째로 들어오는 인자가 스택의 맨 위 (top) 에 와야 합니다. (순서에 주의하세요)
    
- ***The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.***
    
    프로그램은 스택 a를 작은 숫자가 스택의 top에 오도록 순서대로 정렬하기 위해 가능한 한 적은 개수의 명령어를 사용해야 하고, 사용한 명령어의 목록을 마지막에 출력하여야 합니다.
    
- ***Instructions must be separaed by a ’\n’ and nothing else.***
    
    명령어는 '\n'으로만 구분되어 출력되어야 합니다.
    
- ***The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operations tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.***
    
    최종 목표는 스택을 가능한 한 적은 개수의 명령어로 정렬하는 것입니다. 동료평가 시에는 프로그램에서 출력한 명령어의 개수와 평가에서 요구하는 최대 명령어 개수를 비교할 것입니다. 프로그램에서 출력한 명령어 수가 최대 개수를 넘어서거나 제대로 정렬되지 않았을 경우, 점수를 받을 수 없습니다.
    
- ***In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.***
    
    오류가 발생했을 경우에는, 표준 출력으로 `Error`와 줄바꿈 문자 (\n) 를 출력하여야 합니다. 오류의 예시로는 특정 인자값이 정수가 아니거나, 정수보다 큰 인자값이 들어오거나, 중복된 인자가 들어오는 경우가 있습니다.
    

`$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>`

### ***During the defence we’ll provide a binnary to properly check your program. It will work as follows:***

동료평가 시에 사용할 수 있는 Checker 프로그램이 제공됩니다. 이 프로그램은 다음과 같이 사용할 수 있습니다 :

`$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>`

### ***If the program `checker_OS` displays `KO`, it means that your `push_swap` came up with a list of instructions that doesn’t sort the list. The `checker_OS` program is available in the resources of the project on the intranet. You can find in the bonus section of this document a description of how it works.***

`checker_OS` 프로그램이 `KO`를 출력했다면, 여러분의 `push_swap`이 출력한 명령어 리스트가 정수 배열 정렬에 실패하였다는 의미입니다. `checker_OS` 프로그램은 인트라에서 다운로드 받으실 수 있으며, 어떻게 동작하는지는 과제의 보너스 섹션에서 알아보실 수 있습니다.

# **Chapter 6**

## **Bonus part**

### ***We will look at your bonus part if and only if your mandatory part is EXCELLENT. This means that your must complete the mandatory part, beginning to end, and your error management needs to be flawless, even in cases of twisted or bad usage. If that’s not the case, your bonuses will be totally IGNORED.***

보너스 파트는 여러분의 필수 파트 구현이 **완벽할 때** 만 평가될 것입니다. 이 말인즉슨 여러분은 필수 파트를 처음부터 끝까지 제대로 구현하여 어떠한 인자를 넣거나 돌발 상황이 발생하여도 오류가 없어야 합니다. 이 경우가 아니면, 보너스는 완전히 '**무시될**' 것입니다.

### ***The `Push_swap` project lends itself little to the creation of bonus due to its simplicity.***

`push_swap` 과제 그 자체로는 너무 단순하기 때문에 보너스 과제를 내기가 쉽지가 않네요.

### ***However, how about creating your own checker?***

그럼, 여러분만의 체커를 만드는 건 어떨까요?

## **6.1 The "Checker" Program**

- ***Write a program named `checker`, which will get as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given `checker` stops and displays nothing.***
    
    여러분은 스택 a에 들어갈 정수의 목록을 인자값으로 받는 `checker` 프로그램을 작성해야 합니다. 첫 번째로 들어오는 인자가 스택의 맨 위 (top) 에 와야 합니다. (순서에 주의하세요)
    
- ***`checker` will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, `checker` will execute them on the stack received as an argument.***
    
    `checker`를 실행시키면 표준 입력으로 명령어가 들어올 때까지 대기 상태가 됩니다. 명령어는 줄옮김 '\n'으로 구분되어 들어와야 하며, 모든 명령어가 들어왔을 경우 `checker`는 명령어와 입력받은 정수 스택을 이용하여 정렬을 시작합니다.
    
- ***If after executing those instructions, stack `a` is actually sorted and `b` is empty, then `checker` must display "`OK`" followed by a ’\n’ on the standard output. In every other case, `checker` must display "`KO`" followed by a ’\n’ on the standard output.***
    
    명령어 입력이 끝난 뒤 `checker`가 스택을 정렬하였을 때, 스택 `a`는 제대로 정렬되어 있고 스택 `b`는 비어있을 경우, `checker`는 "`OK`"를 '\n'과 함께 표준 출력하여야 합니다. 그 외의 경우, `checker`는 "`KO`"를 '\n'과 함께 출력하여야 합니다.
    
- ***In case of error, you must display `Error` followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted.***
    
    오류가 발생했을 경우에는, 표준 출력으로 `Error`와 줄바꿈 문자 (\n) 를 출력하여야 합니다. 오류의 예시로는 특정 인자값이 정수가 아니거나, 정수보다 큰 인자값이 들어오거나, 중복된 인자가 들어오거나, 존재하지 않는 명령어를 입력받았거나, 입력 포맷이 잘못되었을 때 등이 있습니다.
    

> ℹ️
> 
> 
> ### ***Thanks to the checker program, you will be able to check if the list of instructions you’ll generate with the program `push_swap` is actually sorting the stack properly.***
> 
> 체커 프로그램 덕에, 여러분의 `push_swap` 프로그램이 출력한 명령어 목록이 정상적으로 스택을 정렬하는지 쉽게 검사할 수 있습니다.
> 

`$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>./checker "" 1
Error
$>`

> ⚠️
> 
> 
> ### ***You DO NOT have to reproduce the exact same behavior as the binary we are giving to you. It is mandatory to manage the errors but it is up to you how you decide to parse the arguments.***
> 
> 제공되는 Checker 파일과 완벽하게 똑같은 동작을 할 필요는 없습니다. 오류 처리는 필수이지만, 인자값을 어떻게 파싱하여 읽어들일지는 여러분의 자유입니다.
> 

# **Chapter 7**

## **Submission and peer correction**

### ***Submit your work on your `GiT` repository as usual. Only the work on your repository will be graded.***

항상 그래왔듯, 여러분의 결과물을 `GIT` 레포지토리에 제출하세요. 레포지토리에 있는 과제물만이 채점될 것입니다.

### ***Good luck to all!***

행운을 빌어요!
