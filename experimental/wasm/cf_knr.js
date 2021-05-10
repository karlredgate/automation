var _cf = _cf || [];

function _bmak_ir() {
        bmak.start_ts = Date.now ? Date.now() : +new Date;

        bmak.kact  = ""; bmak.ke_cnt = 0; bmak.ke_vel = 0;
        bmak.mact  = ""; bmak.mme_cnt = 0; bmak.mduce_cnt = 0; bmak.me_vel = 0;
        bmak.pact  = ""; bmak.pme_cnt = 0; bmak.pduce_cnt = 0; bmak.pe_vel = 0;
        bmak.tact  = ""; bmak.tme_cnt = 0; bmak.tduce_cnt = 0; bmak.te_vel = 0;
        bmak.doact = ""; bmak.doe_cnt = 0; bmak.doe_vel = 0;
        bmak.dmact = ""; bmak.dme_cnt = 0; bmak.dme_vel = 0;
        bmak.vcact = ""; bmak.vc_cnt = 0;

        bmak.aj_indx = 0;
        bmak.aj_ss = 0;
        bmak.aj_type = -1;
        bmak.aj_indx_doact = 0;
        bmak.aj_indx_dmact = 0;
        bmak.aj_indx_tact = 0;

        bmak.me_cnt = 0;
        bmak.pe_cnt = 0;
        bmak.te_cnt = 0;
}

function _bmak_get_cf_date() {
        if (Date.now) {
            return Date.now();
        } else {
            return +new Date;
        }
}

function _bmak_sd_debug(str) {
        if (bmak.js_post)  return;
        var new_trace_info = str;
        if (typeof _sd_trace == 'string') {
            _sd_trace = _sd_trace + new_trace_info;
        } else {
            _sd_trace = new_trace_info;
        }
}

function _bmak_gd() {
    var _user_agent = bmak.uar();
    var uas         = "" + bmak.ab(_user_agent);
    var b2          = bmak.start_ts / 2;
    var awidth    = window.screen ? window.screen.availWidth : -1;
    var aheight   = window.screen ? window.screen.availHeight : -1;
    var width     = window.screen ? window.screen.width : -1;
    var height    = window.screen ? window.screen.height : -1;
    var winwidth  = window.innerWidth || document.body.clientWidth;
    var winheight = window.innerHeight || document.body.clientHeight;
    var owidth    = window.outerWidth || document.body.outerWidth;
    bmak.z1 = bmak.pi(bmak.start_ts / (bmak.y1 * bmak.y1));
    var rn  = Math.random();
    var msb = bmak.pi(rn * 1000 / 2);
    var rns = rn + '';

    rns = rns.slice(0, 11) + msb;
    bmak.get_browser();
    bmak.bc();
    bmak.bmisc();
    var dinfo = _user_agent + ",uaend," + bmak.xagg + "," + bmak.psub + "," + bmak.lang + "," +
	bmak.prod + "," + bmak.plen + "," + bmak.pen + "," + bmak.wen + "," + bmak.den + "," + bmak.z1 + "," + bmak.d3 + "," +
	awidth + "," + aheight + "," + width + "," + height + "," +
	winwidth + "," + winheight + "," + owidth + "," + bmak.bd() + "," + uas + "," + rns + "," + b2 + ",loc:" + bmak.loc;
    return dinfo;
}

function _bmak_get_browser() {
    if (navigator.productSub) bmak.psub = navigator.productSub;
    if (navigator.language  ) bmak.lang = navigator.language;
    if (navigator.product   ) bmak.prod = navigator.product;
    bmak.plen = (typeof navigator.plugins != "undefined") ? navigator.plugins.length : -1;
}

function _bmak_bc() {
    var aelen = (window.addEventListener) ? 1 : 0;
    var xhren = (window.XMLHttpRequest) ? 1 : 0;
    var xdren = (window.XDomainRequest) ? 1 : 0;
    var een   = (window.emit) ? 1 : 0;
    var doeen = (window.DeviceOrientationEvent) ? 1 : 0;
    var dmeen = (window.DeviceMotionEvent) ? 1 : 0;
    var teen  = (window.TouchEvent) ? 1 : 0;
    var sen   = (window.spawn) ? 1 : 0;
    var iwen  = (window.innerWidth) ? 1 : 0;
    var owen  = (window.outerWidth) ? 1 : 0;
    var cen   = (window.chrome) ? 1 : 0;
    var fpben = (Function.prototype.bind) ? 1 : 0;
    var ben   = (window.Buffer) ? 1 : 0;
    var peen  = (window.PointerEvent) ? 1 : 0;
    bmak.xagg = aelen + (xhren << 1) + (xdren << 2) + (een << 3) + (doeen << 4) + (dmeen << 5) + (teen << 6) + (sen << 7) + (iwen << 8) + (owen << 9) + (cen << 10) + (fpben << 11) + (ben << 12) + (peen << 13);
}

function _bmak_bd() {
    var b = [];
    var cpen = (window.callPhantom) ? 1 : 0;
    b.push(",cpen:" + cpen);
    var i1 = new Function("return/*@cc_on!@*/!1")() ? 1 : 0;
    b.push("i1:" + i1);
    var dm = (typeof document.documentMode == "number") ? 1 : 0;
    b.push("dm:" + dm);
    var cwen = (window.chrome && window.chrome.webstore) ? 1 : 0;
    b.push("cwen:" + cwen);
    var non = (navigator.onLine) ? 1 : 0;
    b.push("non:" + non);
    var opc = (window.opera) ? 1 : 0;
    b.push("opc:" + opc);
    var fc = (typeof InstallTrigger !== 'undefined') ? 1 : 0;
    b.push("fc:" + fc);
    var sc = (window.HTMLElement && Object.prototype.toString.call(window.HTMLElement).indexOf('Constructor') > 0) ? 1 : 0;
    b.push("sc:" + sc);
    var wrc = (typeof window.RTCPeerConnection === "function" || typeof window.mozRTCPeerConnection === "function" || typeof window.webkitRTCPeerConnection === "function") ? 1 : 0;
    b.push("wrc:" + wrc);
    var isc = ('mozInnerScreenY' in window) ? window.mozInnerScreenY : 0;
    b.push("isc:" + isc);
    bmak.d2 = bmak.pi((bmak.z1) / 23);
    var vib = (typeof navigator.vibrate === "function") ? 1 : 0;
    b.push("vib:" + vib);
    var bat = (typeof navigator.getBattery === "function") ? 1 : 0;
    b.push("bat:" + bat);
    var x11 = (!Array.prototype.forEach) ? 1 : 0;
    b.push("x11:" + x11);
    var x12 = ('FileReader' in window) ? 1 : 0;
    b.push("x12:" + x12);
    return b.join(",");
}

function _bmak_getmr() {
    try {
	if (typeof performance == "undefined" || typeof performance.now == "undefined" || typeof JSON == "undefined"){
	    bmak.mr = "undef";
	    return;
	}
	var resultsStr = "";
	var samples=1000;
	var fnArr=[Math.abs,Math.acos,Math.asin, Math.atanh,Math.cbrt,Math.exp,Math.random,Math.round,Math.sqrt,isFinite, isNaN, parseFloat, parseInt, JSON.parse];
	for (var fn=0; fn<fnArr.length;fn++) {
	    var answer=0;
	    var statsArr=[];
	    var tdelta = 0;
	    var base_t0 = performance.now();
	    var j=0;
	    var median = 0;
	    if (typeof fnArr[fn] != "undefined"){
		for (j=0; (j<samples) && (tdelta<0.6); j++) {
		    var t0 = performance.now();
		    for (var k=0; k<4000; k++) {
			answer=fnArr[fn](3.14);
		    }
		    var t1 = performance.now();
		    statsArr.push(Math.round(1000*(t1 - t0)));
		    tdelta = (t1-base_t0);
		}
		var array1=statsArr.sort();
		median = array1[Math.floor(array1.length/2)]/5;
	    }
	    resultsStr = resultsStr + median + ",";
	}
	bmak.mr = resultsStr;
    } catch(e) {
	bmak.mr = "exception";
    }
},

function _bmak_bpd() {
    bmak.sd_debug('<bpd>');
    var tbpd = 0;
    try {
	tbpd = bmak.get_cf_date();
	var deltat = bmak.updatet();
	var dtck = "3";
	if (bmak.ckie) {
	    dtck = bmak.get_cookie();
	}
	var dinfo = bmak.gd();
	var do_str = window.DeviceOrientationEvent ? "do_en" : "do_dis";
	var dm_str = window.DeviceMotionEvent ? "dm_en" : "dm_dis";
	var touch_str = window.TouchEvent ? "t_en" : "t_dis";
	var event_en_mask = do_str + "," + dm_str + "," + touch_str;
	var forminfo = bmak.forminfo();
	var page_url = bmak.getdurl();
	var aj_stat = bmak.aj_type + "," + bmak.aj_indx;
	if (!bmak.fpcf.fpValCalculated && (bmak.js_post == 0 || bmak.aj_indx > 0)) {
	    bmak.fpcf.fpVal();
	}
	var tot_vel = bmak.ke_vel + bmak.me_vel + bmak.doe_vel + bmak.dme_vel + bmak.te_vel + bmak.pe_vel;
	var dt = bmak.get_cf_date() - bmak.start_ts;
	var w8 = bmak.pi(bmak.d2 / 6);
	var nfas = bmak.fas();
	var misc_stat_arr = [
	    bmak.ke_vel, bmak.me_vel, bmak.te_vel, bmak.doe_vel, bmak.dme_vel,
	    bmak.pe_vel, tot_vel, deltat, bmak.init_time, bmak.start_ts,
	    bmak.fpcf.td, bmak.d2, bmak.ke_cnt, bmak.me_cnt, w8,
	    bmak.pe_cnt, bmak.te_cnt, dt, bmak.ta, bmak.n_ck,
	    dtck, bmak.ab(dtck), bmak.fpcf.rVal, bmak.fpcf.rCFP, nfas
	];
	var misc_stat = misc_stat_arr.join(',');
	var fps = "" + bmak.ab(bmak.fpcf.fpValstr);
	var sel = bmak.sed();
	bmak.sensor_data =
	    bmak.ver        + "-1,2,-94,-100," +
	    dinfo           + "-1,2,-94,-101," +
	    event_en_mask   + "-1,2,-94,-105," +
	    bmak.informinfo + "-1,2,-94,-102," +
	    forminfo        + "-1,2,-94,-108," +
	    bmak.kact       + "-1,2,-94,-110," +
	    bmak.mact       + "-1,2,-94,-117," +
	    bmak.tact       + "-1,2,-94,-111," +
	    bmak.doact      + "-1,2,-94,-109," +
	    bmak.dmact      + "-1,2,-94,-114," +
	    bmak.pact       + "-1,2,-94,-103," +
	    bmak.vcact      + "-1,2,-94,-112," +
	    page_url        + "-1,2,-94,-115," +
	    misc_stat       + "-1,2,-94,-106," +
	    aj_stat;
	bmak.sensor_data = bmak.sensor_data +
	    "-1,2,-94,-119," + bmak.mr +
	    "-1,2,-94,-122," + sel;
	var c1 = bmak.ab( bmak.sensor_data );
	bmak.sensor_data = bmak.sensor_data +
	    "-1,2,-94,-70,"  + bmak.fpcf.fpValstr +
	    "-1,2,-94,-80,"  + fps +
	    "-1,2,-94,-116," + bmak.o9 +
	    "-1,2,-94,-118," + c1 +
	    "-1,2,-94,-121,";
	bmak.sd_debug(',s1:' + bmak.sensor_data.slice(0, 10));
    } catch (e) {
	try {
	    bmak.sd_debug(',s2:' + e);
	    bmak.sensor_data = bmak.ver + "-1,2,-94,-100," + bmak.uar() + "-1,2,-94,-120," + e;
	} catch (e) {
	    bmak.sd_debug(',s3:' + e);
	}
    }
    try {
	var ek = bmak.od(bmak.cs, bmak.api_public_key).slice(0, 16);
	var hr = Math.floor(bmak.get_cf_date() / 3600000);
	var odt = bmak.get_cf_date();
	var odsd = ek + bmak.od(hr, ek) + bmak.sensor_data;
	bmak.sensor_data = odsd + ";" + (bmak.get_cf_date() - tbpd) + ";" + bmak.tst + ";" + (bmak.get_cf_date() - odt);
    } catch (e) { }
    try {
	if (bmak.sdfn.length == 0) {
	    bmak.sd_debug(',s4');
	    if (document.getElementById("sensor_data")) {
		bmak.sd_debug(',s5');
		document.getElementById("sensor_data").value = bmak.sensor_data;
	    }
	} else {
	    bmak.sd_debug(',s6:');
	    for (var x = 0; x < bmak.sdfn.length; x++) {
		bmak.sd_debug(',a-' + bmak.sdfn[x]);
		if (document.getElementById(bmak.sdfn[x])) {
		    bmak.sd_debug(',b');
		    document.getElementById(bmak.sdfn[x]).value = bmak.sensor_data;
		    var tmp = document.getElementById(bmak.sdfn[x]).value;
		    if (typeof tmp == 'string') {
			bmak.sd_debug(',c-' + tmp.slice(0, 5));
		    } else {
			bmak.sd_debug(',c-null');
		    }
		} else {
		    bmak.sd_debug(',d');
		}
	    }
	}
    } catch (e) {
	bmak.sd_debug(',s7:' + e + ',' + bmak.sensor_data);
    }
    bmak.sd_debug('</bpd>');
}

fucntion _bmak_apicall_bm(url, ptype, callback) {
    var xmlhttp;
    if (typeof window.XMLHttpRequest != "undefined") {
	xmlhttp = new XMLHttpRequest();
    } else {
	if (typeof window.XDomainRequest != "undefined") {
	    xmlhttp = new XDomainRequest();
	    xmlhttp.onload = function() {
		this.readyState = 4;
		if (this.onreadystatechange instanceof Function) this.onreadystatechange();
	    }
	} else {
	    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
    }
    xmlhttp.open("POST", url, ptype);
    if (typeof xmlhttp.withCredentials != "undefined") {
	xmlhttp.withCredentials = true;
    }
    var obj = '{"sensor_data":"' + bmak.sensor_data + '"}';
    xmlhttp.onreadystatechange = function() {
	xmlhttp.readyState > 3 && callback && callback(xmlhttp);
    };
    xmlhttp.send(obj);
}






var bmak = {
    ver: 1.28,
    ke_cnt_lmt: 150,
    mme_cnt_lmt: 25,
    mduce_cnt_lmt: 75,
    pme_cnt_lmt: 25,
    pduce_cnt_lmt: 25,
    tme_cnt_lmt: 25,
    tduce_cnt_lmt: 25,
    doe_cnt_lmt: 10,
    dme_cnt_lmt: 10,
    vc_cnt_lmt: 100,
    doa_throttle: 0,
    dma_throttle: 0,
    session_id: "default_session",
    js_post: false,
    loc: "",
    cf_url: ('https:' === document.location.protocol ? 'https://' : 'http://') + "apid.cformanalytics.com/api/v1/attempt",
    auth: "",
    api_public_key: null,
    aj_lmt_doact: 1,
    aj_lmt_dmact: 1,
    aj_lmt_tact: 1,
    ce_js_post: 0, //clickenter_js_post
    init_time: 0,
    informinfo: "",
    prevfid: -1,
    fidcnt: 0,
    sensor_data: 0,
    ins: null,
    cns: null,
    enGetLoc: 0,
    enReadDocUrl: 0,
    disFpCalOnTimeout: 0,
    xagg: -1, pen: -1,
    brow: "", browver: "",
    psub: "-", lang: "-", prod: "-",
    plen: -1,
    doadma_en: 0,
    sdfn: [],
    d2: 0,
    d3: 0,
    thr: 0,
    cs: "0a46G5m17Vrp4o4c",
    hn: "unk",
    z1: 0,
    o9: 0,
    vc: "",
    y1: 2016,
    ta: 0,
    tst: -1,
    t_tst: 0,
    ckie: "_abck",
    n_ck: "0",
    ckurl: 0,
    bm: false,
    mr: "-1",
    altFonts: false,
    rst: false,
    runFonts: true,
    fsp: false, // force secure protocol https

    get_cf_date: _bmak_get_cf_date,
    sd_debug: _bmak_sd_debug,

    pi: function (a) {
        return parseInt(a);
    },

    uar: function() {
        return window.navigator.userAgent.replace(/\\|"/g, '');
    },

    gd: _bmak_gd,
    get_browser: _bmak_get_browser,
    bc: _bmak_bc,

    bmisc: function () {
        bmak.pen = (window._phantom) ? 1 : 0;
        bmak.wen = (window.webdriver) ? 1 : 0;
        bmak.den = (window.domAutomation) ? 1 : 0;
    },

    bd: _bmak_bd,

    fas: function () {
        try {
            var n =
		((Boolean(navigator.credentials)) +
		 (Boolean(navigator.appMinorVersion) << 1) +
		 (Boolean(navigator.bluetooth) << 2) +
		 (Boolean(navigator.storage) << 3) +
		 (Boolean(Math.imul) << 4) +
		 (Boolean(navigator.getGamepads) << 5) +
		 (Boolean(navigator.getStorageUpdates) << 6) +
		 (Boolean(navigator.hardwareConcurrency) << 7) +
		 (Boolean(navigator.mediaDevices) << 8) +
		 (Boolean(navigator.mozAlarms) << 9) +
		 (Boolean(navigator.mozConnection) << 10) +
		 (Boolean(navigator.mozIsLocallyAvailable) << 11) +
		 (Boolean(navigator.mozPhoneNumberService) << 12) +
		 (Boolean(navigator.msManipulationViewsEnabled) << 13) +
		 (Boolean(navigator.permissions) << 14) +
		 (Boolean(navigator.registerProtocolHandler) << 15) +
		 (Boolean(navigator.requestMediaKeySystemAccess) << 16) +
		 (Boolean(navigator.requestWakeLock) << 17) +
		 (Boolean(navigator.sendBeacon) << 18) +
		 (Boolean(navigator.serviceWorker) << 19) +
		 (Boolean(navigator.storeWebWideTrackingException) << 20) +
		 (Boolean(navigator.webkitGetGamepads) << 21) +
		 (Boolean(navigator.webkitTemporaryStorage) << 22) +
		 (Boolean(Number.parseInt) << 23) +
		 (Boolean(Math.hypot) << 24));
            return n;
        }
        catch (e) {
            return 0;
        }
    },

    getmr: _bmak_getmr,

    sed: function(){
        var sel = 0;
	if (window["$cdc_asdjflasutopfhvcZLmcfl_"]) sel = "1";
	if (document["$cdc_asdjflasutopfhvcZLmcfl_"]) sel = "1";
        var att_webd = 0;
	if(window.document.documentElement.getAttribute("webdriver") != null) att_webd = "1";
        var nav_webd = 0;
	if (typeof navigator.webdriver != "undefined" && navigator.webdriver) nav_webd = "1";
        var win_webd = 0;
	if (typeof window.webdriver != "undefined") win_webd = "1";
        var xp = 0;
	if (typeof window.XPathResult != "undefined"|| typeof document.XPathResult != "undefined") xp = "1";
        var att_dri = 0;
	if (window.document.documentElement.getAttribute("driver") != null) att_dri = "1";
        var att_sel = 0;
	if (window.document.documentElement.getAttribute("selenium") != null) att_sel = "1";
        var sel_arr = [sel, att_webd, nav_webd, win_webd, xp, att_dri, att_sel]
        return sel_arr.join(',');
    },

    cma: function (subEvent, eventtype) {
        try {
            if (((eventtype == 1) && (bmak.mme_cnt < bmak.mme_cnt_lmt)) ||
                ((eventtype != 1) && (bmak.mduce_cnt < bmak.mduce_cnt_lmt))) {
                var mainEvent = subEvent ? subEvent : window.event;
                var xcoord = -1;
                var ycoord = -1;
                if (mainEvent && mainEvent.pageX && mainEvent.pageY) {
                    xcoord = Math.floor(mainEvent.pageX);
                    ycoord = Math.floor(mainEvent.pageY);
                } else {
                    if (mainEvent && mainEvent.clientX && mainEvent.clientY) {
                        xcoord = Math.floor(mainEvent.clientX);
                        ycoord = Math.floor(mainEvent.clientY);
                    }
                }
                var toElemObj = mainEvent.toElement;
                if (toElemObj == null) toElemObj = mainEvent.target;
                var fid = bmak.gf(toElemObj);
                var ts = bmak.get_cf_date() - bmak.start_ts;
                var new_mact = bmak.me_cnt + "," + eventtype + "," + ts + "," + xcoord + "," + ycoord;
                if (eventtype != 1) {
                    new_mact = new_mact + "," + fid;
                    var mbutton = (typeof mainEvent.which != "undefined") ? mainEvent.which : mainEvent.button;
                    if (mbutton != null && mbutton != 1) new_mact = new_mact + "," + mbutton;
                }
                new_mact = new_mact + ";";
                bmak.me_vel = bmak.me_vel + bmak.me_cnt + eventtype + ts + xcoord + ycoord;
                bmak.mact = bmak.mact + new_mact;
                bmak.ta += ts;
            }
            if (eventtype == 1) bmak.mme_cnt++;
            else bmak.mduce_cnt++;
            bmak.me_cnt++;
            if ((bmak.js_post) && (eventtype == 3)) {
                bmak.aj_type = 1;
                bmak.bpd();
                bmak.pd(true);
                bmak.ce_js_post = 1;
            }
        } catch (e) {
        }
    },

    x2: function () {
        var b = bmak.ff;
        var x = b(98) + b(109) + b(97) + b(107) + b(46) + b(103) + b(101) + b(116);
        x = x + b(95) + b(99) + b(102) + b(95);
        x = "return " + x + b(100) + b(97) + b(116) + b(101) + b(40) + b(41);
        x = x + ";";
        var y = new Function(x);
        return y();
    },

    cpa: function (subEvent, eventtype) {
        try {
            var ap = false;
            if (((eventtype == 1) && (bmak.pme_cnt < bmak.pme_cnt_lmt)) ||
                ((eventtype != 1) && (bmak.pduce_cnt < bmak.pduce_cnt_lmt))) {
                var mainEvent = subEvent ? subEvent : window.event;
                if (mainEvent && mainEvent.pointerType != "mouse") { // extra condition
                    ap = true;
                    var xcoord = -1;
                    var ycoord = -1;
                    if (mainEvent && mainEvent.pageX && mainEvent.pageY) {
                        xcoord = Math.floor(mainEvent.pageX);
                        ycoord = Math.floor(mainEvent.pageY);
                    } else if (mainEvent && mainEvent.clientX && mainEvent.clientY) {
                        xcoord = Math.floor(mainEvent.clientX);
                        ycoord = Math.floor(mainEvent.clientY);
                    }
                    var ts = bmak.get_cf_date() - bmak.start_ts;
                    var new_pact = bmak.pe_cnt + "," + eventtype + "," + ts + "," + xcoord + "," + ycoord + ";";
                    bmak.pe_vel = bmak.pe_vel + bmak.pe_cnt + eventtype + ts + xcoord + ycoord;
                    bmak.pact = bmak.pact + new_pact;
                    bmak.ta += ts;
                    if (eventtype == 1) bmak.pme_cnt++;
                    else bmak.pduce_cnt++;
                }
            }
            if (eventtype == 1) bmak.pme_cnt++;
            else bmak.pduce_cnt++;
            bmak.pe_cnt++;
            if ((bmak.js_post) && (eventtype == 3) && ap) {
                bmak.aj_type = 2;
                bmak.bpd();
                bmak.pd(true);
                bmak.ce_js_post = 1;
            }
        } catch (e) {
        }
    },

    ab: function (str) {
        if (str == null) return -1;
        try {
            var sum = 0;
            for (var i = 0; i < str.length; i++) {
                var x = str.charCodeAt(i);
                if (x < 128) {
                    sum = sum + x;
                }
            }
            return sum;
        } catch (e) {
            return -2;
        }
    },

    ff: function (a) {
        return String.fromCharCode(a);
    },

    to: function () {
        var x = bmak.x2() % 10000000;
        bmak.d3 = x;
        var y = x;
        for (var i = 0; i < 5; i++) {
            var d = bmak.pi(x / (Math.pow(10, i))) % 10;
            var d1 = d + 1;
            var f = "return a" + bmak.cc(d) + d1 + ";";
            var newFunc = new Function("a", f);
            y = newFunc(y);
        }
        bmak.o9 = y;
    },

    gf: function (obj) {
        var x;
        if (obj == null) {
            x = document.activeElement;
        }
        else x = obj;
        if (document.activeElement == null) return -1;
        var x_name = x.getAttribute("name");
        if (x_name == null) {
            var x_id = x.getAttribute("id");
            if (x_id == null) return -1;
            else return bmak.ab(x_id);
        }
        return bmak.ab(x_name);
    },

    cc: function (a) {
        var x = a % 4;
        if (x == 2) x = 3;
        var y = 42 + x;
        return String.fromCharCode(y);
    },

    isIgn: function (sk) {
        var el = document.activeElement;
        if (document.activeElement == null) return 0;
        var type_str = el.getAttribute("type");
        var type_int = (type_str == null) ? -1 : bmak.get_type(type_str);
        if ((type_int == 1) && (bmak.fidcnt > 12) && (sk == -2)) return 1;
        else return 0;
    },

    cka: function (subEvent, eventtype) {
        try {
            var mainEvent = subEvent ? subEvent : window.event;
            var sk = -1;
            var capture = 1;
            if (bmak.ke_cnt < bmak.ke_cnt_lmt && mainEvent) {
                sk = mainEvent.keyCode;
                var sc = mainEvent.charCode;
                var shiftOn = mainEvent.shiftKey ? 1 : 0;
                var ctrlOn = mainEvent.ctrlKey ? 1 : 0;
                var metaOn = mainEvent.metaKey ? 1 : 0;
                var altOn = mainEvent.altKey ? 1 : 0;
                var flags = shiftOn * 8 + ctrlOn * 4 + metaOn * 2 + altOn;
                var ts = bmak.get_cf_date() - bmak.start_ts;
                var fid = bmak.gf(null);
                var dbg = 0;

                if ((sc) && (sk)) { //IE8 sc is not defined
                    if ((sc != 0) && (sk != 0) && (sc != sk)) sk = -1;
                    else sk = (sk != 0) ? sk : sc;
                }
                // else sk simply used


                if ((ctrlOn == 0) && (metaOn == 0) && (altOn == 0) && (sk >= 32)) {
                    if ((eventtype == 3) && (sk >= 32) && (sk <= 126)) sk = -2;
                    else if ((sk >= 33) && (sk <= 47)) sk = -3; //arrow, etc keys
                    else if ((sk >= 112) && (sk <= 123)) sk = -4; //Function keys
                    else sk = -2;
                }

                if (fid != bmak.prevfid) {
                    bmak.fidcnt = 0;
                    bmak.prevfid = fid;
                }
                else bmak.fidcnt = bmak.fidcnt + 1;
                var isIgn = bmak.isIgn(sk);

                if (isIgn == 0) {
                    var new_kact = bmak.ke_cnt + "," + eventtype + "," + ts + "," +
                        sk + "," + dbg + "," + flags + "," + fid;
                    if (mainEvent.isTrusted != null && mainEvent.isTrusted === false)
                        new_kact = new_kact + ",0";
                    new_kact = new_kact + ";";

                    bmak.kact = bmak.kact + new_kact;
                    bmak.ke_vel = bmak.ke_vel + bmak.ke_cnt + eventtype + ts + sk + flags + fid;
                    bmak.ta += ts;
                }
                else capture = 0;
            }
            if (capture && mainEvent) bmak.ke_cnt++; //since we only capture if capture and MainEvent
            if ((bmak.js_post) && (eventtype == 1) && ((sk == 13) || (sk == 9))) {
                bmak.aj_type = 3;
                bmak.bpd();
                bmak.pd(true);
                bmak.ce_js_post = 1;
            }
        } catch (e) {
        }
    },

    cta: function (subEvent, eventtype) {
        try {
            if (((eventtype == 1) && (bmak.tme_cnt < bmak.tme_cnt_lmt)) ||
                ((eventtype != 1) && (bmak.tduce_cnt < bmak.tduce_cnt_lmt))) {
                var mainEvent = subEvent ? subEvent : window.event;
                var xcoord = -1, ycoord = -1;
                if (mainEvent && mainEvent.pageX && mainEvent.pageY) {
                    xcoord = Math.floor(mainEvent.pageX);
                    ycoord = Math.floor(mainEvent.pageY);
                } else {
                    if (mainEvent && mainEvent.clientX && mainEvent.clientY) {
                        xcoord = Math.floor(mainEvent.clientX);
                        ycoord = Math.floor(mainEvent.clientY);
                    }
                }
                var ts = bmak.get_cf_date() - bmak.start_ts;
                var new_tact = bmak.te_cnt + "," + eventtype + "," + ts + "," + xcoord + "," + ycoord + ";";
                bmak.tact = bmak.tact + new_tact;
                bmak.ta += ts;
                bmak.te_vel = bmak.te_vel + bmak.te_cnt + eventtype + ts + xcoord + ycoord;
                bmak.doa_throttle = 0;
                bmak.dma_throttle = 0;
            }
            if (eventtype == 1) bmak.tme_cnt++;
            else bmak.tduce_cnt++;
            bmak.te_cnt++;
            if ((bmak.js_post) && (eventtype == 2) && (bmak.aj_indx_tact < bmak.aj_lmt_tact)) {
                bmak.aj_type = 5;
                bmak.bpd();
                bmak.pd(true);
                bmak.ce_js_post = 1;
                bmak.aj_indx_tact++;
            }
        } catch (e) {
        }
    },

    getFloatVal: function (val) {
        try {
            if (bmak.chknull(val) != -1 && !isNaN(val)) {
                var floatVal = parseFloat(val);
                if (!isNaN(floatVal)) {
                    return floatVal.toFixed(2);
                }
            }
        } catch (e) {
        }
        return -1;
    },

    cdoa: function (event) {
        try {
            if ((bmak.doe_cnt < bmak.doe_cnt_lmt) && (bmak.doa_throttle < 2) && event) {
                var ts = bmak.get_cf_date() - bmak.start_ts;
                var alpha = bmak.getFloatVal(event.alpha);
                var beta = bmak.getFloatVal(event.beta);
                var gamma = bmak.getFloatVal(event.gamma);
                var new_doact = bmak.doe_cnt + "," + ts + "," + alpha + "," + beta + "," + gamma + ";";
                bmak.doact = bmak.doact + new_doact;
                bmak.ta += ts;
                bmak.doe_vel = bmak.doe_vel + bmak.doe_cnt + ts;
                bmak.doe_cnt++;
            }
            if ((bmak.js_post) && (bmak.doe_cnt > 1) && (bmak.aj_indx_doact < bmak.aj_lmt_doact)) {
                //skip the very first (hence doe_cnt>1)
                bmak.aj_type = 6;
                bmak.bpd();
                bmak.pd(true);
                bmak.ce_js_post = 1;
                bmak.aj_indx_doact++;
            }
            bmak.doa_throttle++;
        } catch (e) {
        }
    },

    cdma: function (event) {
        try {
            if ((bmak.dme_cnt < bmak.dme_cnt_lmt) && (bmak.dma_throttle < 2) && event) {
                var ts = bmak.get_cf_date() - bmak.start_ts;
                var xa = -1, ya = -1, za = -1;
                if (event.acceleration) {
                    xa = bmak.getFloatVal(event.acceleration.x);
                    ya = bmak.getFloatVal(event.acceleration.y);
                    za = bmak.getFloatVal(event.acceleration.z);
                }
                var xag = -1, yag = -1, zag = -1;
                if (event.accelerationIncludingGravity) {
                    xag = bmak.getFloatVal(event.accelerationIncludingGravity.x);
                    yag = bmak.getFloatVal(event.accelerationIncludingGravity.y);
                    zag = bmak.getFloatVal(event.accelerationIncludingGravity.z);
                }
                var ralpha = -1, rbeta = -1, rgamma = 1;
                if (event.rotationRate) {
                    ralpha = bmak.getFloatVal(event.rotationRate.alpha);
                    rbeta = bmak.getFloatVal(event.rotationRate.beta);
                    rgamma = bmak.getFloatVal(event.rotationRate.gamma);
                }
                var new_dmact = bmak.dme_cnt + "," + ts + "," + xa + "," + ya + "," + za + "," + xag + "," + yag + "," + zag + "," + ralpha + "," + rbeta + "," + rgamma + ";";
                bmak.dmact = bmak.dmact + new_dmact;
                bmak.ta += ts;
                bmak.dme_vel = bmak.dme_vel + bmak.dme_cnt + ts;
                bmak.dme_cnt++;
            }
            if ((bmak.js_post) && (bmak.dme_cnt > 1) && (bmak.aj_indx_dmact < bmak.aj_lmt_dmact)) {
                //skip the very first (hence dme_cnt>1)
                bmak.aj_type = 7;
                bmak.bpd();
                bmak.pd(true);
                bmak.ce_js_post = 1;
                bmak.aj_indx_dmact++;
            }
            bmak.dma_throttle++;
        } catch (e) {
        }
    },

    get_type: function (type_str) {
        type_str = type_str.toLowerCase();
        if ((type_str == "text") || (type_str == "search") || (type_str == "url") || (type_str == "email") || (type_str == "tel") || (type_str == "number")) return 0;
        else if (type_str == "password") return 1;
        else return 2;
    },

    chknull: function (val) {
        return (val == null) ? -1 : val;
    },


    forminfo: function () {
        var txt = "";
        var ins = "";

        var inputEl = document.getElementsByTagName('input');
        var ac = -1;
        for (var i = 0; i < inputEl.length; i++) {
            var el = inputEl[i];
            var el_name = bmak.ab(el.getAttribute("name"));
            var el_id = bmak.ab(el.getAttribute("id"));
            var req_str = el.getAttribute("required");
            var req_int = (req_str == null) ? 0 : 1;
            var type_str = el.getAttribute("type");
            var type_int = (type_str == null) ? -1 : bmak.get_type(type_str);
            var ac_str = el.getAttribute("autocomplete");
            if (ac_str == null) ac = -1;
            else {
                ac_str = ac_str.toLowerCase();
                if (ac_str == "off") ac = 0;
                else if (ac_str == "on") ac = 1;
                else ac = 2;
            }
            var default_val = el.defaultValue;
            var val = el.value;
            var new_val = 0;
            var default_val_present = 0;
            if (default_val && default_val.length != 0) {
                default_val_present = 1;
            }
            if (val && val.length != 0 && (!default_val_present || val != default_val)) {
                new_val = 1;
            }
            if (type_int != 2) {
                txt = txt + type_int + "," + ac + "," + new_val + "," + req_int + "," + el_id + "," + el_name + "," + default_val_present + ";";
            }
            ins = ins + new_val + ";";
        }
        if (bmak.ins == null) bmak.ins = ins;
        bmak.cns = ins;
        return txt;
    },

    startdoadma: function () {
        if ((bmak.doadma_en == 0) && window.addEventListener) {
            window.addEventListener('deviceorientation', bmak.cdoa, true);
            window.addEventListener('devicemotion', bmak.cdma, true);
            bmak.doadma_en = 1;
        }
        bmak.doa_throttle = 0;
        bmak.dma_throttle = 0;
    },


    updatet: function () {
        return bmak.get_cf_date() - bmak.start_ts;
    },

    htm: function (event) { bmak.cta(event, 1); },
    hts: function (event) { bmak.cta(event, 2); },
    hte: function (event) { bmak.cta(event, 3); },
    htc: function (event) { bmak.cta(event, 4); },

    hmm: function (event) { bmak.cma(event, 1); },
    hc:  function (event) { bmak.cma(event, 2); },
    hmd: function (event) { bmak.cma(event, 3); },
    hmu: function (event) { bmak.cma(event, 4); },

    hpd: function (event) { bmak.cpa(event, 3); },
    hpu: function (event) { bmak.cpa(event, 4); },

    hkd: function (event) { bmak.cka(event, 1); },
    hku: function (event) { bmak.cka(event, 2); },
    hkp: function (event) { bmak.cka(event, 3); },

    cfsubmit: function () {
        bmak.sd_debug('<cfsubmit/>');
        if (bmak.js_post) {
            bmak.aj_type = 4;
            bmak.bpd();
            if ((bmak.ce_js_post == 0) && (bmak.cns != bmak.ins)) { //try to ensure atleast 1 post
                bmak.pd(true);
            }
        }
        else bmak.bpd();
    },

    getdurl: function () {
        if (bmak.enReadDocUrl) {
            return document.URL.replace(/\\|"/g, '');
        }
        return '';
    },

    x1: function () {
        return Math.floor((1 + Math.random()) * 0x1000000).toString(36);
    },

    gck: function () {
        var ck = bmak.x1() + bmak.x1() + bmak.x1() + bmak.x1();
        bmak.set_cookie(bmak.ckie, ck + '_' + bmak.ab(ck));
        return ck;
    },

    set_cookie: function (name, value) {
        if (typeof document.cookie != "undefined") {
            document.cookie = name + '=' + value + "; path=/; expires=Fri, 01 Feb 2025 08:00:00 GMT;";
        }
    },

    get_cookie: function () {
        try {
            var dtck = bmak.cookie_chk_read(bmak.ckie);
            if (!dtck) {
                bmak.n_ck = 1;
                if (bmak.bm) {
                    dtck = "2";
                }
                else {
                    dtck = bmak.gck();
                }
            }
            return dtck;
        } catch (e) {
        }
        return "2";
    },

    cookie_chk_read: function (cname) {
        if (document.cookie) {
            var cnameEQ = cname + '=';
            var cookieArr = document.cookie.split('; ');
            for (var i = 0; i < cookieArr.length; i++) {
                var c = cookieArr[i];
                if (c.indexOf(cnameEQ) === 0) {
                    var cvalue = c.substring(cnameEQ.length, c.length);
                    if (bmak.bm) {
                        if (cvalue.indexOf('~') != -1) {
                            return cvalue;
                        }
                    }
                    else {
                        return cvalue;
                    }
                }
            }
        }
        return false;
    },

    bpd: _bmak_bpd,

    od: function (str, key) {
        try {
            str = String(str);
            key = String(key);
            var new_d = [];
            var keylen = key.length;
            if (keylen > 0) {
                for (var i = 0; i < str.length; i++) {
                    var val = str.charCodeAt(i);
                    var ch = str.charAt(i);
                    var rotation_val_abs = key.charCodeAt(i % keylen);
                    val = bmak.rir(val, 47, 57, rotation_val_abs);
                    if (val != str.charCodeAt(i)) {
                        ch = String.fromCharCode(val);
                    }
                    new_d.push(ch);
                }
                if (new_d.length > 0) {
                    return new_d.join('');
                }
            }
        } catch (e) {
        }
        return str;
    },

    rir: function (val, r1, r2, rot) {
        if ((val > r1) && (val <= r2)) {
            val = val + (rot % (r2 - r1));
            if (val > r2) {
                val = val - r2 + r1;
            }
        }
        return val;
    },

    lvc: function (type) {
        try {
            if (bmak.vc_cnt < bmak.vc_cnt_lmt) {
                var ts = bmak.get_cf_date() - bmak.start_ts;
                var new_vcact = type + "," + ts + ";";
                bmak.vcact = bmak.vcact + new_vcact;
            }
            bmak.vc_cnt++;
        } catch (e) {
        }
    },
    hvc: function () {
        try {
            var type = 1;
            if (document[bmak.hn]) type = 0;
            bmak.lvc(type);
        } catch (e) {
        }
    },
    hb: function (event) {
        bmak.lvc(2);
    },
    hf: function (event) {
        bmak.lvc(3);
    },
    rve: function () {
        if (typeof document.hidden !== "undefined") {
            bmak.hn = "hidden";
            bmak.vc = "visibilitychange";
        } else if (typeof document.mozHidden !== "undefined") {
            bmak.hn = "mozHidden";
            bmak.vc = "mozvisibilitychange";
        } else if (typeof document.msHidden !== "undefined") {
            bmak.hn = "msHidden";
            bmak.vc = "msvisibilitychange";
        } else if (typeof document.webkitHidden !== "undefined") {
            bmak.hn = "webkitHidden";
            bmak.vc = "webkitvisibilitychange";
        }

        if (document.addEventListener) {
            if (bmak.hn != "unk") document.addEventListener(bmak.vc, bmak.hvc, true);
        }
        else if (document.attachEvent) {
            if (bmak.hn != "unk") document.attachEvent(bmak.vc, bmak.hvc);
        }
        window.onblur = bmak.hb;
        window.onfocus = bmak.hf;
    },

    startTracking: function () {
        bmak.startdoadma();
        bmak.to();
        setInterval(function () {
            bmak.startdoadma();
        }, 3000);
        if (document.addEventListener) {
            document.addEventListener("touchmove", bmak.htm, true);
            document.addEventListener("touchstart", bmak.hts, true);
            document.addEventListener("touchend", bmak.hte, true);
            document.addEventListener("touchcancel", bmak.htc, true);

            document.addEventListener("mousemove", bmak.hmm, true);
            document.addEventListener("click", bmak.hc, true);
            document.addEventListener("mousedown", bmak.hmd, true);
            document.addEventListener("mouseup", bmak.hmu, true);

            document.addEventListener("pointerdown", bmak.hpd, true);
            document.addEventListener("pointerup", bmak.hpu, true);

            document.addEventListener("keydown", bmak.hkd, true);
            document.addEventListener("keyup", bmak.hku, true);
            document.addEventListener("keypress", bmak.hkp, true);

        } else if (document.attachEvent) {
            document.attachEvent("touchmove", bmak.htm);
            document.attachEvent("touchstart", bmak.hts);
            document.attachEvent("touchend", bmak.hte);
            document.attachEvent("touchcancel", bmak.htc);

            document.attachEvent("onmousemove", bmak.hmm);
            document.attachEvent("onclick", bmak.hc);
            document.attachEvent("onmousedown", bmak.hmd);
            document.attachEvent("onmouseup", bmak.hmu);

            document.attachEvent("onpointerdown", bmak.hpd);
            document.attachEvent("onpointerup", bmak.hpu);

            document.attachEvent("onkeydown", bmak.hkd);
            document.attachEvent("onkeyup", bmak.hku);
            document.attachEvent("onkeypress", bmak.hkp);
        }
        bmak.rve();
        bmak.informinfo = bmak.forminfo();
        if (bmak.js_post) {
            bmak.aj_type = 0;
            bmak.bpd();
            bmak.pd(true);
        }

    },

    gb: function (str, indx) {
        var cc = str.charCodeAt(indx);
        cc = (cc > 255) ? 0 : cc;
        return cc;
    },

    encode: function (str) {
        if (typeof btoa != "undefined") return btoa(str);
        var b64_chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';
        var outstr = '';
        var floor3_len = Math.floor(str.length / 3) * 3;
        var inc0, inc1, inc2, outc0_indx, outc1_indx, outc2_indx, outc3_indx;
        for (var i = 0; i < floor3_len; i = i + 3) {
            inc0 = bmak.gb(str, i);
            inc1 = bmak.gb(str, i + 1);
            inc2 = bmak.gb(str, i + 2);

            outc0_indx = inc0 >> 2;
            outc1_indx = ((inc0 & 0x3) << 4) + (inc1 >> 4);
            outc2_indx = ((inc1 & 0xF) << 2) + (inc2 >> 6);
            outc3_indx = (inc2 & 0x3F);

            outstr = outstr + b64_chars.charAt(outc0_indx) + b64_chars.charAt(outc1_indx)
                + b64_chars.charAt(outc2_indx) + b64_chars.charAt(outc3_indx);
        }
        if (str.length % 3 == 1) {
            inc0 = bmak.gb(str, i);

            outc0_indx = inc0 >> 2;
            outc1_indx = (inc0 & 0x3) << 4;

            outstr = outstr + b64_chars.charAt(outc0_indx) + b64_chars.charAt(outc1_indx) + "==";
        }
        if (str.length % 3 == 2) {
            inc0 = bmak.gb(str, i);
            inc1 = bmak.gb(str, i + 1);

            outc0_indx = inc0 >> 2;
            outc1_indx = ((inc0 & 0x3) << 4) + (inc1 >> 4);
            outc2_indx = (inc1 & 0xF) << 2;

            outstr = outstr + b64_chars.charAt(outc0_indx) + b64_chars.charAt(outc1_indx) + b64_chars.charAt(outc2_indx) + "=";
        }
        return outstr;
    },

    ie9OrLower: function () {
        try {
            if (typeof navigator.appVersion == "string" && navigator.appVersion.indexOf("MSIE") != -1) {
                var ver = parseFloat(navigator.appVersion.split("MSIE")[1]);
                if (ver <= 9) {
                    return true;
                }
            }
        } catch (e) {
        }
        return false;
    },


    apicall: function (url, ptype) {
        var xmlhttp;
        if (window.XDomainRequest) {
            xmlhttp = new XDomainRequest();
        } else {
            if (window.XMLHttpRequest) {
                xmlhttp = new XMLHttpRequest();
            }
            else {
                xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
            }
        }
        xmlhttp.open("POST", url, ptype);
        var val = bmak.encode(bmak.api_public_key + ":");
        bmak.auth = ',"auth" : "' + val + '"';
        if (xmlhttp.setRequestHeader) {
            xmlhttp.setRequestHeader("Content-type", "application/json");
            xmlhttp.setRequestHeader("Authorization", "Basic " + val);
            bmak.auth = "";
        }
        var obj = '{'
            + '"session_id" : "' + bmak.session_id + '",'
            + '"sensor_data" : "' + bmak.sensor_data + '"'
            + bmak.auth
            + '}';
        xmlhttp.send(obj);
    },

    apicall_bm: _bmak_apicall_bm,

    pd_en: function () {
        var x;
        var url = bmak.getdurl();
        if (bmak.thr == 0)
            return 1;
        if (url.indexOf('home.html') > -1) x = 1;
        else x = 0;

        if ((bmak.start_ts % 10) != 0) return 0;
        if (bmak.aj_indx > 3) return 0;
        if (x && (bmak.aj_indx > 0)) return 0;
        return 1;
    },

    pd: function (ptype) {
        var en;
        en = bmak.pd_en();
        if (en) {
            if (bmak.bm) {
                if (bmak.check_stop_protocol()) {
                    bmak.apicall_bm(bmak.cf_url, ptype, bmak.patp);
                }
            } else {
                bmak.apicall(bmak.cf_url, ptype);
            }
            bmak.aj_indx = bmak.aj_indx + 1;
        }
    },
    // returns true if we should autpost, false otherwise
    // handles stop protocol logic
    // 1. if reset > -1, reset all counters (calling ir()), set reset to -1
    // 2. if stop = -1 or aj_ss < stop, continue autopost (true), otherwise stop (false)
    check_stop_protocol: function () {
        var signals = bmak.get_stop_signals();
        var reset_n = signals[0];
        if (!bmak.rst && reset_n > -1) {
	    _bmak_ir();
            bmak.rst = true;
        }
        var stop_n = signals[1];
        if (stop_n == -1 || bmak.aj_ss < stop_n) {
            return true;
        }
        else {
            return false;
        }
    },
    // return an array of 2 values: [0] -> reset_n, [1] -> stop_n
    // read and parse _abck cookie for these values
    // on error return [-1, -1] for unset/unused values
    get_stop_signals: function () {
        var signals = [-1, -1];
        var _abck_value = bmak.cookie_chk_read(bmak.ckie);
        if (_abck_value !== false) {
            try {
                var parts = decodeURIComponent(_abck_value).split('~');
                if (parts.length >= 4) {
                    var stop_n = bmak.pi(parts[1]);
                    var reset_n = bmak.pi(parts[3]);
                    stop_n = isNaN(stop_n) ? -1 : stop_n;
                    reset_n = isNaN(reset_n) ? -1 : reset_n;
                    signals = [reset_n, stop_n]
                }
            }
            catch (e) {
            }
        }
        return signals
    },
    // process autopost response
    // for now, just increment success counter without checking
    // set bmak.rst flag to false
    patp: function (xmlhttp) {
        // (console) ? console.log(xmlhttp.responseText) : alert(xmlhttp.responseText)
        bmak.aj_ss++;
        bmak.rst = false;
    },

    listFunctions: {
        _setJsPost: function (a) {
            bmak.js_post = a;
            if (bmak.js_post) bmak.enReadDocUrl = 1; //force to 1 if front end post
        },
        _setSessionId:         function (a) { bmak.session_id        = a; },
        _setJavaScriptKey:     function (a) { bmak.api_public_key    = a; },
        _setEnAddHidden:       function (a) { bmak.enAddHidden       = a; },
        _setInitTime:          function (a) { bmak.init_time         = a; },
        _setApiUrl:            function (a) { bmak.cf_url            = a; },
        _setEnGetLoc:          function (a) { bmak.enGetLoc          = a; },
        _setEnReadDocUrl:      function (a) { bmak.enReadDocUrl      = a; },
        _setDisFpCalOnTimeout: function (a) { bmak.disFpCalOnTimeout = a; },
        _setCookie:            function (a) { bmak.ckie              = a; },
        _setCS:                function (a) { bmak.cs = (String(a) + bmak.cs).slice(0, 16); },
        _setFsp: function (a) {
            bmak.fsp = a;
            if (bmak.fsp) {
                bmak.cf_url = bmak.cf_url.replace(/^http:\/\//i, 'https://');
            }
        },
        _setBm: function (a) {
            bmak.bm = a;
            if (bmak.bm) {
                //set akamai botmanager specific parameters
                bmak.cf_url = ((bmak.fsp) ? 'https:' : document.location.protocol) + '//' + document.location.hostname + "/_bm/_data";
                bmak.api_public_key = "afSbep8yjnZUjq3aL010jO15Sawj2VZfdYK8uY90uxq";
                bmak.js_post = true;
                bmak.enReadDocUrl = 1;
                bmak.runFonts = false;
            }
        },
        _setSDFieldNames: function () {
            try {
                var y;
                for (y = 0; y < arguments.length; y += 1) {
                    bmak.sdfn.push(arguments[y]);
                }
            } catch (e) {
                bmak.sd_debug(',setSDFN:' + e);
            }
        },
        _setUseAltFonts: function (a) {
            bmak.altFonts = a;
        }
    },

    applyFunc: function () {
        var a, b, c;
        for (a = 0; a < arguments.length; a += 1) {
            c = arguments[a];
        }
        b = c.shift();
        if (bmak.listFunctions[b]) {
            bmak.listFunctions[b].apply(bmak.listFunctions, c);
        }
    }

};

bmak.sd_debug('<init/>');

for (var i = 0; i < _cf.length; i++) {
    bmak.applyFunc(_cf[i]);
}

bmak.sd_debug('<setSDFN>' + bmak.sdfn.join() + '</setSDFN>');
_cf = { push: bmak.applyFunc };

(function (context) {

    var fpcf = {};
    context["fpcf"] = fpcf;

    fpcf.sf4 = function () {
        var ua = bmak.uar();
        if (~ua.indexOf('Version/4.0') && (~ua.indexOf('iPad;') || ~ua.indexOf('iPhone') || ~ua.indexOf('Mac OS X 10_5'))) {
            return true;
        }
        return false;
    };

    fpcf.fpValstr = "-1";
    fpcf.fpValCalculated = false;
    fpcf.rVal = "-1";
    fpcf.rCFP = "-1";
    fpcf.cache = {};
    fpcf.td = -999999;
    fpcf.clearCache = function () {
        fpcf.cache = {};
    };

    fpcf.fpVal = function () {
        fpcf.fpValCalculated = true;
        try {
            var t1 = 0;
            if (Date.now) t1 = Date.now(); else t1 = +new Date();
            var data = fpcf.data();
            fpcf.fpValstr = data.replace(/\"/g, "\\\"");

            var t2 = 0;
            if (Date.now) t2 = Date.now(); else t2 = +new Date();
            fpcf.td = t2 - t1;
        } catch (e) {
        }
    };

    fpcf.timezoneOffsetKey = function () {
        return new Date().getTimezoneOffset();
    };

    fpcf.data = function () {
        var cd = screen.colorDepth ? screen.colorDepth : -1;
        var pd = screen.pixelDepth ? screen.pixelDepth : -1;
        var ce = navigator.cookieEnabled ? navigator.cookieEnabled : -1;
        var je = navigator.javaEnabled ? navigator.javaEnabled() : -1;
        var dnt = navigator.doNotTrack ? navigator.doNotTrack : -1;
        var fonts = "default";
        if(bmak.runFonts){
            fonts = bmak.altFonts ? fpcf.fonts_optm() : fpcf.fonts();
        }else{
            fonts = "dis";
        }
        var all = [
            fpcf.canvas(), fonts, fpcf.pluginInfo(),
            fpcf.sessionStorageKey(), fpcf.localStorageKey(), fpcf.indexedDbKey(),
            fpcf.timezoneOffsetKey(), fpcf.webrtcKey(), cd,
            pd, ce, je,
            dnt
        ];

        return all.join(';');
    };

    fpcf.PLUGINS = [
        "WebEx64 General Plugin Container",
        "YouTube Plug-in",
        "Java Applet Plug-in",
        "Shockwave Flash",
        "iPhotoPhotocast",
        "SharePoint Browser Plug-in",
        "Chrome Remote Desktop Viewer",
        "Chrome PDF Viewer",
        "Native Client",
        "Unity Player",
        "WebKit-integrierte PDF",
        "QuickTime Plug-in",
        "RealPlayer Version Plugin",
        "RealPlayer(tm) G2 LiveConnect-Enabled Plug-In (32-bit)",
        "Mozilla Default Plug-in",
        "Adobe Acrobat",
        "AdobeAAMDetect",
        "Google Earth Plug-in",
        "Java Plug-in 2 for NPAPI Browsers",
        "Widevine Content Decryption Module",
        "Microsoft Office Live Plug-in",
        "Windows Media Player Plug-in Dynamic Link Library",
        "Google Talk Plugin Video Renderer",
        "Edge PDF Viewer",
        "Shockwave for Director",
        "Default Browser Helper",
        "Silverlight Plug-In"
    ];

    fpcf.pluginInfo = function () {
        if (typeof navigator.plugins == "undefined")
            return null;
        var len = fpcf.PLUGINS.length;
        var out_list = "";
        for (var i = 0; i < len; i++) {
            var p = fpcf.PLUGINS[i];
            if (navigator.plugins[p] !== undefined) {
                out_list = out_list + "," + i;
            }
        }
        return out_list;
    };

    fpcf.canvas = function () {
        try {
            if (fpcf.cache.canvas !== undefined) {
                return fpcf.cache.canvas;
            }
            var result = -1;
            if (!fpcf.sf4()) {
                var canvas = document.createElement("canvas");
                canvas.width = 280;
                canvas.height = 60;
                canvas.style.display = "none";


                if (typeof canvas.getContext === 'function') {
                    var c = canvas.getContext("2d");
                    var text = "<@nv45. F1n63r,Pr1n71n6!";

                    c.fillStyle = "rgb(102, 204, 0)";
                    c.fillRect(100, 5, 80, 50);

                    c.fillStyle = "#f60";
                    c.font = "16pt Arial";
                    c.fillText(text, 10, 40);

                    c.strokeStyle = "rgb(120, 186, 176)";
                    c.arc(80, 10, 20, 0, Math.PI, false);
                    c.stroke();
                    var x = canvas.toDataURL();
                    result = 0;
                    for (var i = 0; i < x.length; i++) {
                        var y = x.charCodeAt(i);
                        result = ((result << 5) - result) + y;
                        result = result & result;
                    }
                    result = result.toString();

                    var sc = document.createElement("canvas");
                    sc.width = 16;
                    sc.height = 16;

                    var co = sc.getContext("2d");
                    co.font = "6pt Arial";
                    fpcf.rVal = (Math.floor(Math.random() * 1000)).toString();
                    co.fillText(fpcf.rVal, 1, 12);
                    var z = sc.toDataURL();
                    var scr = 0;
                    for (var j = 0; j < z.length; j++) {
                        var w = z.charCodeAt(j);
                        scr = ((scr << 5) - scr) + w;
                        scr = scr & scr;
                    }
                    fpcf.rCFP = scr.toString();
                }
            }
            return result
        } catch (e) {
            return "exception";
        }
    };

    fpcf.fonts_optm = function () {
        var maxTime = 200;
        var t0 = bmak.get_cf_date();
        var output = [];
        if (!fpcf.sf4()) {
            var stdfont_names = ["sans-serif", "monospace"];
            var stdfont_widths = [0, 0];
            var stdfont_heights = [0, 0];
            var container = document.createElement("div");
            container.style.cssText = "position: relative; left: -9999px; visibility: hidden; display: block !important";
            var i;
            for (i = 0; i < stdfont_names.length; i++) {
                var temp_span_obj = document.createElement("span");
                temp_span_obj.innerHTML = "abcdefhijklmnopqrstuvxyz1234567890;+-.";
                temp_span_obj.style.fontSize = "90px"; //large font to get more accurate width/height
                temp_span_obj.style.fontFamily = stdfont_names[i];

                container.appendChild(temp_span_obj);
            }
            document.body.appendChild(container);
            for (i = 0; i < container.childNodes.length; i++) {
                temp_span_obj = container.childNodes[i];
                stdfont_widths[i] = temp_span_obj.offsetWidth;
                stdfont_heights[i] = temp_span_obj.offsetHeight;
            }
            document.body.removeChild(container);
            if ((bmak.get_cf_date() - t0) > maxTime){
                return ""
            }
            var fonts_to_check = [
                "Geneva", "Lobster", "New York", "Century", "Apple Gothic",
                "Minion Pro", "Apple LiGothic", "Century Gothic", "Monaco", "Lato",
                "Fantasque Sans Mono", "Adobe Braille", "Cambria", "Futura", "Bell MT",
                "Courier", "Courier New", "Calibri", "Avenir Next", "Birch Std",
                "Palatino", "Ubuntu Regular", "Oswald", "Batang", "Ubuntu Medium",
                "Cantarell", "Droid Serif", "Roboto", "Helvetica Neue", "Corsiva Hebrew",
                "Adobe Hebrew", "TI-Nspire", "Comic Neue", "Noto", "AlNile",
                "Palatino-Bold", "ArialHebrew-Light", "Avenir", "Papyrus", "Open Sans",
                "Times", "Quicksand", "Source Sans Pro", "Damascus", "Microsoft Sans Serif"
            ];

            var container1 = document.createElement("div");
            container1.style.cssText = "position: relative; left: -9999px; visibility: hidden; display: block !important";
            var font_list = [];
            for (var j = 0; j < fonts_to_check.length; j++) {
                var temp_div_obj = document.createElement("div");
                for (i = 0; i < stdfont_names.length; i++) {
                    var temp_span_obj = document.createElement("span");
                    temp_span_obj.innerHTML = "abcdefhijklmnopqrstuvxyz1234567890;+-.";
                    temp_span_obj.style.fontSize = "90px"; //large font to get more accurate width/height
                    temp_span_obj.style.fontFamily = fonts_to_check[j] + "," + stdfont_names[i];
                    temp_div_obj.appendChild(temp_span_obj);
                }
                container1.appendChild(temp_div_obj);

            }
            if ((bmak.get_cf_date() - t0) > maxTime){
                return ""
            }
            document.body.appendChild(container1);

            for (var j = 0; j < container1.childNodes.length; j++) {
                var exists = false;
                var temp_div_obj = container1.childNodes[j];
                for (i = 0; i < temp_div_obj.childNodes.length; i++) {
                    var temp_span_obj = temp_div_obj.childNodes[i];
                    if (temp_span_obj.offsetWidth !== stdfont_widths[i] || temp_span_obj.offsetHeight !== stdfont_heights[i]) {
                        exists = true;
                        break;
                    }
                }
                if (exists) {
                    font_list.push(j);
                }
                if ((bmak.get_cf_date() - t0) > maxTime){
                    break;
                }
            }
            document.body.removeChild(container1);
            output = font_list.sort()
        }
        return output.join(",");
    };


    fpcf.fonts = function () {
        var output = [];
        if (!fpcf.sf4()) {

            var stdfont_names = ["serif", "sans-serif", "monospace"];
            var stdfont_widths = [0, 0, 0];
            var stdfont_heights = [0, 0, 0];

            var temp_span_obj = document.createElement("span");
            temp_span_obj.innerHTML = "abcdefhijklmnopqrstuvxyz1234567890;+-.";
            temp_span_obj.style.fontSize = "90px"; //large font to get more accurate width/height
            var i;
            for (i = 0; i < stdfont_names.length; i++) {
                temp_span_obj.style.fontFamily = stdfont_names[i];
                document.body.appendChild(temp_span_obj);
                stdfont_widths[i] = temp_span_obj.offsetWidth;
                stdfont_heights[i] = temp_span_obj.offsetHeight;
                document.body.removeChild(temp_span_obj);
            }

            var fonts_to_check = [
                "Geneva", "Lobster", "New York", "Century", "Apple Gothic",
                "Minion Pro", "Apple LiGothic", "Century Gothic", "Monaco", "Lato",
                "Fantasque Sans Mono", "Adobe Braille", "Cambria", "Futura", "Bell MT",
                "Courier", "Courier New", "Calibri", "Avenir Next", "Birch Std",
                "Palatino", "Ubuntu Regular", "Oswald", "Batang", "Ubuntu Medium",
                "Cantarell", "Droid Serif", "Roboto", "Helvetica Neue", "Corsiva Hebrew",
                "Adobe Hebrew", "TI-Nspire", "Comic Neue", "Noto", "AlNile",
                "Palatino-Bold", "ArialHebrew-Light", "Avenir", "Papyrus", "Open Sans",
                "Times", "Quicksand", "Source Sans Pro", "Damascus", "Microsoft Sans Serif"
            ];

            var font_list = [];

            for (var j = 0; j < fonts_to_check.length; j++) {
                var exists = false;
                for (i = 0; i < stdfont_names.length; i++) {
                    temp_span_obj.style.fontFamily = fonts_to_check[j] + "," + stdfont_names[i];
                    document.body.appendChild(temp_span_obj);
                    if (temp_span_obj.offsetWidth !== stdfont_widths[i] || temp_span_obj.offsetHeight !== stdfont_heights[i]) {
                        exists = true
                    }
                    document.body.removeChild(temp_span_obj);
                    if (exists) {
                        font_list.push(j);
                        break;
                    }
                }
            }
            output = font_list.sort()
        }
        return output.join(",");
    };

    fpcf.webrtcKey = function () {
        return typeof window.RTCPeerConnection === "function" || typeof window.mozRTCPeerConnection === "function" || typeof window.webkitRTCPeerConnection === "function";
    };


    fpcf.indexedDbKey = function () {
        if (fpcf.hasIndexedDB()) {
            return true;
        }
        return false;
    };

    fpcf.sessionStorageKey = function () {
        if (fpcf.hasSessionStorage()) {
            return true;
        }
        return false;
    };
    fpcf.localStorageKey = function () {
        if (fpcf.hasLocalStorage()) {
            return true;
        }
        return false;
    };

    fpcf.hasSessionStorage = function () {
        try {
            return !!window.sessionStorage;
        } catch (e) {
            return false;
        }
    };
    fpcf.hasLocalStorage = function () {
        try {
            return !!window.localStorage;
        } catch (e) {
            return false;
        }
    };
    fpcf.hasIndexedDB = function () {
        return !!window.indexedDB;
    };

})(bmak);


try { if (bmak.ckie) { bmak.get_cookie(); } } catch (e) { }

try {
    _bmak_ir();
    bmak.t_tst = bmak.get_cf_date();
    bmak.startTracking();
    bmak.tst = bmak.get_cf_date() - bmak.t_tst;
    if (!bmak.disFpCalOnTimeout) {
        setTimeout(bmak.fpcf.fpVal, 100);
    }
    for(var i=0;i<3;i++) setTimeout(bmak.getmr, 400+i*5000);
} catch (e) { }
