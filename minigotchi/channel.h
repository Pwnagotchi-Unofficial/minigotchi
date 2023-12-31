/////////////////////////////////////////////
// channel.h: header files for channel.cpp //
/////////////////////////////////////////////

#ifndef CHANNEL_H
#define CHANNEL_H

class ChannelHandler {
public:
    ChannelHandler(int initialChannel);
    void cycleChannels();
    int getCurrentChannel();

private:
    int currentChannel;
    int channelList[10] // 10 channels
};

// global instance
extern ChannelHandler channelHandler;

#endif // CHANNEL_H
