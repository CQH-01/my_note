```
ssh-keygen -t rsa -C "your_email.com"
```

- 密钥类型可以用 -t 选项指定。如果没有指定则默认生成用于SSH-2的RSA密钥。这里使用的是rsa。
- -C来指定所指定的注释，可以方便用户标识这个密钥，指出密钥的用途或其他有用的信息。所以在这里输入自己的邮箱或者其他都行
- 生成的密钥在 `C:\Users\your_pc_user_name\.ssh` 目录下 `your_pc_user_name` 是你的电脑登陆的用户名
- `.pub` 才是秘钥



设置用户名(这是你登录github的用户名)

```
`git config --global user.name 'pylemonorg'`
```

设置用户名邮箱(这是你github的邮箱)

```
git config --global user.email 'your_email@gmail.com'`
```

可以通过 `git config --list` 查看信息







1.从远程仓库clone工程到本地

```
  git clone -b 分支名称 http://10.1.1.11/service/tmall-service.git localDestDirectory
```

   localDestDirectory意为本地工作目录，该目录中需要指定工程名称，现在你可以在你的工作目录中创建文件，进行代码开发工作了

2.输入 git status  查看当前文件修改状态

3.将本地修改文件添加到本地git缓存区中

 ```
 git add .  或者 git add xxx
 ```

4.推送修改到本地git库中

```
git commit -m "修复XXbug" 
```

5.取回远程主机某个分支的更新，再与本地的指定分支合并。

```
git pull origin main   //
```

例如：origin 为远程主机名称，mybranch 为 远程分支名

*需要输入你的git账号和密码才能拉取。*

6.把当前提交到git本地仓库的代码推送到远程主机origin的mybranch分支上。

```
git push origin main  //
```

