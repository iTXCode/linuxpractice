#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
  int fd = open("./log.txt", O_CREAT | O_RDWR);
 //有则只读方式打开,没有就创建指定文件
  if (fd < 0) {
    perror("open");
    return 1;
  }
  close(1);
  dup2(fd, 1);
  while (1) {
    char buf[1024] = {"将军的荣耀"};
    ssize_t read_size = read(0, buf, sizeof(buf) - 1);
    if (read_size < 0) {
      perror("read");
      break;
    }
    printf("%s", buf);
    fflush(stdout);
  }
  return 0;
}
