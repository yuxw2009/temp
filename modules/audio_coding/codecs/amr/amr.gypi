{
  'targets': [
    {
      'target_name': 'AMR',
      'type': 'static_library',
      'include_dirs': [
        'include',
      ],
      'sources': [
        'amr_interface.c',
      ],
      "link_settings": {
        'libraries': [
          '/home/ubuntu/WebRTC/src/webrtc/modules/audio_coding/codecs/amr/libopencoreamr.a',
        ],
      },
    },
  ],
}