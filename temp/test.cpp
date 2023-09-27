#include <QApplication>
#include <QDialog>
#include <QMainWindow>
#include <QPushButton>

class LoginDialog : public QDialog {
  Q_OBJECT

public:
  LoginDialog() {
    initUI();
  }

private slots:
  void login() {
    // 登录成功后，隐藏登录界面并显示主页面
    hide();
    mainWindow->show();
  }

private:
  void initUI() {
    setWindowTitle("登录界面");
    setGeometry(100, 100, 300, 200);

    QPushButton *loginButton = new QPushButton("登录", this);
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::login);
  }

  QMainWindow *mainWindow;
};

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow() {
    initUI();
  }

private:
  void initUI() {
    setWindowTitle("主页面");
    setGeometry(100, 100, 400, 300);
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // 创建登录界面和主页面
  LoginDialog loginDialog;
  MainWindow mainWindow;

  loginDialog.show();

  return app.exec();
}
