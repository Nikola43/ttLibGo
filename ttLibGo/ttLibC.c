/*
C言語のソースを利用可能にしておく
cgoのコンパイルでは、プロジェクトと同じところにあるc、ccファイルが自動的にコンパイル対象になるみたいですね。
ちょっと反則っぽいけど cファイルをincludeしておく
こうするとこのファイルにソースコードが展開されるので、ちゃんとコンパイルされるようになる。

あと内部の関数のvisibilityをhiddenにしておく
これをやっておかないと後で作るttLibGoFaacとかを利用するときに競合してlinkerがこけるため
こんな感じにしてみました。

CFlagsやCXXFlagsで全部hiddenにしてはいけないみたい。cgoのリンクで利用してる関数まで見えなくなると
cgoが動作しなくなるため。

本当ならsource.goのimport Cで括ってるコメントの部分にinclude文を並べてもいいんだけど
C++がうまく動作できないため(goに書くとC言語扱いになる)別ファイルにしてある
*/
#define TT_VISIBILITY_HIDDEN __attribute__ ((visibility("hidden")))
#define TT_VISIBILITY_DEFAULT __attribute__ ((visibility("hidden")))

#include "../ttLibC/ttLibC/container/flv/type/audioTag.c"
#include "../ttLibC/ttLibC/container/flv/type/headerTag.c"
#include "../ttLibC/ttLibC/container/flv/type/metaTag.c"
#include "../ttLibC/ttLibC/container/flv/type/videoTag.c"
#include "../ttLibC/ttLibC/container/flv/flvReader.c"
#include "../ttLibC/ttLibC/container/flv/flvTag.c"
#include "../ttLibC/ttLibC/container/flv/flvWriter.c"
#include "../ttLibC/ttLibC/container/mkv/type/simpleBlock.c"
#include "../ttLibC/ttLibC/container/mkv/mkvReader.c"
#include "../ttLibC/ttLibC/container/mkv/mkvTag.c"
#include "../ttLibC/ttLibC/container/mkv/mkvWriter.c"
#include "../ttLibC/ttLibC/container/mp3/mp3Frame.c"
#include "../ttLibC/ttLibC/container/mp3/mp3Reader.c"
#include "../ttLibC/ttLibC/container/mp3/mp3Writer.c"
#include "../ttLibC/ttLibC/container/mp4/type/ctts.c"
#include "../ttLibC/ttLibC/container/mp4/type/elst.c"
#include "../ttLibC/ttLibC/container/mp4/type/stco.c"
#include "../ttLibC/ttLibC/container/mp4/type/stsc.c"
#include "../ttLibC/ttLibC/container/mp4/type/stsz.c"
#include "../ttLibC/ttLibC/container/mp4/type/stts.c"
#include "../ttLibC/ttLibC/container/mp4/type/trun.c"
#include "../ttLibC/ttLibC/container/mp4/mp4Atom.c"
#include "../ttLibC/ttLibC/container/mp4/mp4Reader.c"
#include "../ttLibC/ttLibC/container/mp4/mp4Writer.c"
#include "../ttLibC/ttLibC/container/mpegts/type/pat.c"
#include "../ttLibC/ttLibC/container/mpegts/type/pes.c"
#include "../ttLibC/ttLibC/container/mpegts/type/pmt.c"
#include "../ttLibC/ttLibC/container/mpegts/type/sdt.c"
#include "../ttLibC/ttLibC/container/mpegts/mpegtsPacket.c"
#include "../ttLibC/ttLibC/container/mpegts/mpegtsReader.c"
#include "../ttLibC/ttLibC/container/mpegts/mpegtsWriter.c"
#include "../ttLibC/ttLibC/container/container.c"
#include "../ttLibC/ttLibC/container/misc2.c"
#include "../ttLibC/ttLibC/frame/audio/aac.c"
#include "../ttLibC/ttLibC/frame/audio/adpcmImaWav.c"
#include "../ttLibC/ttLibC/frame/audio/audio.c"
#include "../ttLibC/ttLibC/frame/audio/mp3.c"
#include "../ttLibC/ttLibC/frame/audio/nellymoser.c"
#include "../ttLibC/ttLibC/frame/audio/opus.c"
#include "../ttLibC/ttLibC/frame/audio/pcmAlaw.c"
#include "../ttLibC/ttLibC/frame/audio/pcmf32.c"
#include "../ttLibC/ttLibC/frame/audio/pcmMulaw.c"
#include "../ttLibC/ttLibC/frame/audio/pcms16.c"
#include "../ttLibC/ttLibC/frame/audio/speex.c"
#include "../ttLibC/ttLibC/frame/audio/vorbis.c"
#include "../ttLibC/ttLibC/frame/video/bgr.c"
#include "../ttLibC/ttLibC/frame/video/flv1.c"
#include "../ttLibC/ttLibC/frame/video/h264.c"
#include "../ttLibC/ttLibC/frame/video/h265.c"
#include "../ttLibC/ttLibC/frame/video/jpeg.c"
#include "../ttLibC/ttLibC/frame/video/theora.c"
#include "../ttLibC/ttLibC/frame/video/video.c"
#include "../ttLibC/ttLibC/frame/video/vp6.c"
#include "../ttLibC/ttLibC/frame/video/vp8.c"
#include "../ttLibC/ttLibC/frame/video/vp9.c"
#include "../ttLibC/ttLibC/frame/video/wmv1.c"
#include "../ttLibC/ttLibC/frame/video/wmv2.c"
#include "../ttLibC/ttLibC/frame/video/yuv420.c"
#include "../ttLibC/ttLibC/frame/frame.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/data/clientObject.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/header/rtmpHeader.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/acknowledgement.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/aggregateMessage.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/amf0Command.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/amf0DataMessage.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/audioMessage.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/rtmpMessage.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/setChunkSize.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/setPeerBandwidth.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/userControlMessage.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/videoMessage.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/message/windowAcknowledgementSize.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/tetty/rtmpClientHandler.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/tetty/rtmpCommandHandler.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/tetty/rtmpDecoder.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/tetty/rtmpEncoder.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/tetty/rtmpHandshake.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/rtmpConnection.c"
//#include "../ttLibC/ttLibC/net/client/rtmp/rtmpStream.c"
//#include "../ttLibC/ttLibC/net/client/websocket/handler.c"
//#include "../ttLibC/ttLibC/net/client/websocket/handshake.c"
//#include "../ttLibC/ttLibC/net/client/websocket/websocket.c"
//#include "../ttLibC/ttLibC/net/net.c"
//#include "../ttLibC/ttLibC/net/tcp.c"
//#include "../ttLibC/ttLibC/net/tetty/bootstrap.c"
//#include "../ttLibC/ttLibC/net/tetty/context.c"
//#include "../ttLibC/ttLibC/net/tetty/promise.c"
//#include "../ttLibC/ttLibC/net/udp.c"
#include "../ttLibC/ttLibC/resampler/audioResampler.c"
#include "../ttLibC/ttLibC/resampler/imageResampler.c"
#include "../ttLibC/ttLibC/resampler/imageResizer.c"
#include "../ttLibC/ttLibC/util/amfUtil.c"
#include "../ttLibC/ttLibC/util/byteUtil.c"
#include "../ttLibC/ttLibC/util/crc32Util.c"
#include "../ttLibC/ttLibC/util/dynamicBufferUtil.c"
#include "../ttLibC/ttLibC/util/flvFrameUtil.c"
#include "../ttLibC/ttLibC/util/hexUtil.c"
#include "../ttLibC/ttLibC/util/ioUtil.c"
#include "../ttLibC/ttLibC/allocator.c"
#include "../ttLibC/ttLibC/ttLibC.c"