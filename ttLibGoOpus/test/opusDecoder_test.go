package test

import (
	"fmt"
	"os"
	"testing"

	"github.com/taktod/ttLibGo/ttLibGo"
	"github.com/taktod/ttLibGo/ttLibGoOpus"
)

func TestOpusDecoder(t *testing.T) {
	{
		in, err := os.Open(os.Getenv("HOME") + "/tools/data/source/test.vp9.opus.webm")
		if err != nil {
			panic(err)
		}
		var count uint32
		var reader ttLibGo.Reader
		if !reader.Init("webm") {
			t.Errorf("reader初期化失敗")
		}
		defer reader.Close()
		var decoder ttLibGoOpus.OpusDecoder
		defer decoder.Close()
		for {
			buffer := make([]byte, 65536)
			length, err := in.Read(buffer)
			if err != nil {
				panic(err)
			}
			if !reader.ReadFrame(
				buffer,
				uint64(length),
				func(frame *ttLibGo.Frame) bool {
					if frame.CodecType == "opus" {
						decoder.Init(frame.SampleRate, frame.ChannelNum)
						return decoder.Decode(
							frame,
							func(frame *ttLibGo.Frame) bool {
								fmt.Println(frame)
								count++
								return true
							})
					}
					return true
				}) {
				t.Errorf("コンテナ読み込み失敗")
				return
			}
			if length < 65536 {
				break
			}
		}
		if count == 0 {
			t.Errorf("デコードされませんでした")
			return
		}
		t.Logf("デコードされた数:%d", count)
	}
}