#!/bin/sh

# Thanks: http://stackoverflow.com/questions/14710257/running-a-cron-job-at-230-am-every-day
# On how to automate process at 2:30 every day (type "date" to get your server time)
# crontab -e
# 30 2 * * * /your/command

echo "Update gtest-yarp-plugins..."
cd $HOME/gtest-yarp-plugins
git pull
echo "Doxy gtest-yarp-plugins..."
cd doc
rm -r html
/usr/bin/doxygen
cd ../..

