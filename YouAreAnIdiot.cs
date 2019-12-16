using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public class YouAreAnIdiot : EditorWindow {
	static Texture2D texture1;
	static Texture2D texture2;

	System.DateTime first;

	[MenuItem ("CustomMenu/you are an idiot %y")]
	public static void CreateWindow () {
		if (texture1 == null) {
			texture1 = (Texture2D) EditorGUIUtility.Load ("youareanidiot-0.png");
		}
		if (texture2 == null) {
			texture2 = (Texture2D) EditorGUIUtility.Load ("youareanidiot-1.png");
		}
		var window = CreateInstance<YouAreAnIdiot> ();
		window.ShowUtility ();
	}

	void Awake () {
		this.minSize = new Vector2 (480, 360);
		this.maxSize = new Vector2 (480, 360);
		this.maximized = false;
		first = System.DateTime.Now;
	}

	bool flag = false;

	void Update () {
		var now = System.DateTime.Now;
		var timediff = (now - first).TotalMilliseconds;
		bool nowflag = (timediff % 800) >= 400;

		if (flag != nowflag) {
			flag = nowflag;
			Repaint ();
		}
	}

	void OnGUI () {
		GUI.DrawTexture (new Rect (0, 0, 480, 360), flag?texture1 : texture2);
	}
}
