import os, sqlite3, time
from flask import Flask, request, jsonify

DB = os.environ.get("CRASH_DB", "crashes.sqlite")
os.makedirs("data", exist_ok=True)

app = Flask(__name__)

def init_db():
    with sqlite3.connect(DB) as c:
        c.execute("""
            CREATE TABLE IF NOT EXISTS crashes(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                ts INTEGER,
                build_id TEXT,
                os TEXT,
                version TEXT,
                signature TEXT,
                top_frame TEXT,
                dmp_path TEXT
            )
        """)
init_db()

@app.post("/minidump")
def minidump():
    f = request.files.get("upload_file_minidump") or request.files.get("minidump") or request.files.get("file")
    if not f:
        return jsonify({"error": "no file"}), 400
    meta = {k: request.form.get(k) for k in ("build_id","os","version")}
    ts = int(time.time())
    path = f"data/{ts}.dmp"
    f.save(path)
    with sqlite3.connect(DB) as c:
        c.execute(
            "INSERT INTO crashes(ts,build_id,os,version,signature,top_frame,dmp_path) VALUES(?,?,?,?,?,?,?)",
            (ts, meta.get("build_id"), meta.get("os"), meta.get("version"), None, None, path)
        )
    return jsonify({"ok": True, "stored": path})

if __name__ == "__main__":
    app.run(host="127.0.0.1", port=int(os.environ.get("PORT", 8080)))
