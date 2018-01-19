#include <signal.h>
#include <unistd.h>
#include <stdio.h>

struct sigaction act;
void handler1() {
  printf("This is final exam?\n");
}

void handler2() {
  printf("Enter your expression: \n");
  int a = 0, b = 0;
  char op;
  scanf("%d %c %d", &a, &op, &b);
  if (op == '+'){
    printf("Add 2 nums = %d\n", a + b);
  }else if (op == '-'){
    printf("Sub b from a = %d\n", a - b);
  }else if (op == '*'){
    printf("Multiply 2 nums = %d\n", a * b);
  }else if (op == '/'){
    printf("Divide a by b = %d\n", a / b);
  }else {
    printf("Something went wrong!\n");
  }
}

void dohandler2() {
  act.sa_handler = SIG_DFL;
  sigaction(SIGINT, &act, NULL);
}

void dohandler1() {
  act.sa_handler = handler2;
  sigaction(SIGINT, &act, NULL);
  signal(SIGALRM, dohandler2);
  alarm(20);
  
}


int main() {

  act.sa_handler = handler1;
  sigemptyset(&act.sa_mask);
  act.sa_flags=0;
  sigaction(SIGINT, &act, NULL);
  signal(SIGALRM, dohandler1);
  alarm(3);
  while(1);
}
