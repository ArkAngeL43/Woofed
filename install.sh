sudo apt-get install libpcap-dev
git clone https://github.com/seladb/PcapPlusPlus.git
cd PcapPlusPlus
./configure-linux.sh --default
make all
sudo make install
cd ..
sudo rm -rf PcapPlusPlus
echo "----------------------------------------------------------"
echo "You are ready to go!"
