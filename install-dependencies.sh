sudo apt-add-repository ppa:wpilib/toolchain -y
sudo apt-get update -q
sudo apt-get install libc6-i386 -y
sudo apt-get install frc-toolchain -y

git clone https://github.com/Impact2585/wpilib-cpp.git
