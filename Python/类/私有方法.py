# coding:utf-8
   
class Dog:

    #私有方法
    def __send_msg(self):
        print("------正在发送短信------")

    #公有方法
    def send_msg(self, new_money):
        if new_money>10000:
            self.__send_msg()     # 仅可以在class内调用私有方法__send_msg
        else:
            print("余额不足,请先充值 再发送短信")

dog = Dog()
dog.send_msg(1000000)       # ------正在发送短信------
dog.send_msg(100)           # 余额不足,请先充值 再发送短信


