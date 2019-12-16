using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public class YouAreAnIdiot : EditorWindow {

  const string MUSIC_PATH = "youareanidiot.mp3";
  const string GRAPHIC_PATH_1 = "youareanidiot-0.png";
  const string GRAPHIC_PATH_2 = "youareanidiot-1.png";
  static Texture2D texture1;
  static Texture2D texture2;
  static Vector2 bound = new Vector2 (1440, 900);
	DateTime first;

  [MenuItem ("CustomMenu/you are an idiot %y")]
  public static void Func () {
    if (texture1 == null) {
      texture1 = (Texture2D) EditorGUIUtility.Load (GRAPHIC_PATH_1);
    }

    if (texture2 == null) {
      texture2 = (Texture2D) EditorGUIUtility.Load (GRAPHIC_PATH_2);
    }

    var window = CreateInstance<YouAreAnIdiot> ();
    window.ShowUtility ();
  }

  [MenuItem ("CustomMenu/Delete %e")]
  public static void Shine () {
    var sceneViews = Resources.FindObjectsOfTypeAll<YouAreAnIdiot> ();
    foreach (var view in sceneViews) {
      view.Close ();
    }
  }

  AudioSource source;

  void Awake () {
    source = GetAudioSource ();
    source.loop = true;
    source.Play ();
    this.minSize = new Vector2 (480, 360);
    this.maxSize = new Vector2 (480, 360);
    this.maximized = false;

    //Vector2 bound = new Vector2 (Screen.currentResolution.width, Screen.currentResolution.height);
    pos = new Vector2 (Random.Range (0, bound.x - minSize.x), Random.Range (40, bound.y - minSize.y));
    if (Random.Range (0, 2) == 0) diff *= new Vector2 (-1, 1);
    if (Random.Range (0, 2) == 0) diff *= new Vector2 (1, -1);
    this.position = new Rect (pos, this.minSize);
		first = DateTime.Now;
  }

  void OnDisable () {
    source.Stop ();
  }

  float t = 0;
  float s = 0;
  bool flag = true;

  Vector2 pos;
  Vector2 diff = new Vector2 (6f, 6f);

  void OnGUI () {
    GUI.DrawTexture (new Rect (0, 0, 480, 360), flag?texture1 : texture2);
  }

  void Update () {
		var now = DateTime.Now;
		var timediff = (now - first).TotalMilliseconds;
		bool nowflag = (timediff % 800) >= 400;

		if (flag != nowflag) {
			flag = nowflag;
			Repaint ();
		}

    s += 1;
    if (s > 1) {
      s -= 1;
      if (pos.x < 0 || pos.x + position.size.x > bound.x) {
        diff *= new Vector2 (-1, 1);
      }
      if (pos.y < 40 || pos.y + position.size.y > bound.y) {
        diff *= new Vector2 (1, -1);
      }
      pos += diff;
      position = new Rect (pos, position.size);
    }
  }

  static AudioSource GetAudioSource () {
    // var gameObjectName = "HideAudioSourceObject";
    // var gameObject = GameObject.Find (gameObjectName);

    // if (gameObject == null) {
    // 	//HideAndDontSave フラグを立てて非表示・保存しないようにする
    // 	gameObject =
    // 		EditorUtility.CreateGameObjectWithHideFlags (gameObjectName,
    // 			HideFlags.HideAndDontSave, typeof (AudioSource));
    // }

    var gameObjectName = "HideAudioSourceObject";

    var gameObject =
      EditorUtility.CreateGameObjectWithHideFlags (gameObjectName,
        HideFlags.HideAndDontSave, typeof (AudioSource));

    var hideAudioSource = gameObject.GetComponent<AudioSource> ();

    if (hideAudioSource.clip == null) {
      hideAudioSource.clip = (AudioClip) EditorGUIUtility.Load (MUSIC_PATH);
      //hideAudioSource.clip =
      //	AssetDatabase.LoadAssetAtPath (musicPath, typeof (AudioClip)) as AudioClip;
    }

    return hideAudioSource;
  }
}
