#!/usr/bin/env bash
set -e
missing=0
[ -f tools/crashpad/handler/crashpad_handler ] || { echo "handler MISSING"; missing=1; }
[ -d tools/crashpad/include/crashpad ] || { echo "headers MISSING (crashpad)"; missing=1; }
[ -d tools/crashpad/include/mini_chromium ] || { echo "headers MISSING (mini_chromium)"; missing=1; }
[ -f tools/crashpad/lib/libcrashpad_client.a ] || { echo "lib_client MISSING"; missing=1; }
[ -f tools/crashpad/lib/libcrashpad_util.a ] || { echo "lib_util MISSING"; missing=1; }
[ -f tools/crashpad/lib/libmini_chromium.a ] || { echo "lib_mini MISSING"; missing=1; }
if [ "$missing" = "0" ]; then
  echo "All Crashpad assets present"
  exit 0
else
  exit 1
fi
