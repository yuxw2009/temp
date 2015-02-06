{
  'targets': [
    {
      'target_name': 'G729',
      'type': 'static_library',
      'include_dirs': [
        'include',
      ],
      'sources': [
        'g729_interface.c',
      ],
      "link_settings": {
        'libraries': [
          '/home/ubuntu/WebRTC/src/webrtc/modules/audio_coding/codecs/g729/libbcgg729.a',
        ],
      },
    },
  ],
}