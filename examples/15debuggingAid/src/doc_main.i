# 1 "doc_main.c"
# 1 "<command-line>"
# 1 "doc_main.c"
...
 38 #include <emx/Fonts.h>
 39 #include <emx/Lcd.h>
 40 #include <emx/Menu.h>
 41 #include <emx/Buttons.h>
 42
 43 #include <avr/pgmspace.h>
 44 #include <avr/eeprom.h>
 45 > #include <avr/interrupt.h>
 46
 47 #include <util/delay.h>
 48
 49 const char TX_Copyright[] PROGMEM = "Copyright";
 50 const char TX_SubMenu[] PROGMEM = "Show submenu";
 51 const char TX_EepromVersionRo[] PROGMEM = "Show EEPROM version";
 52 const char TX_EepromVersion[] PROGMEM = "Edit EEPROM version";
 53 const char TX_SetContrast[] PROGMEM = "Set contrast";
 54 const char TX_ScaledVoltage[] PROGMEM = "Voltage alarm";
 55 const char TX_Protocol[] PROGMEM = "Protocol";
 56
 57 const char TX_Futaba[] PROGMEM = "Futaba";
 58 const char TX_Spectrum[] PROGMEM = "Spectrum";
 59 const char TX_Graupner[] PROGMEM = "Graupner";
 60 const char TX_Jeti[] PROGMEM = "Jeti";
 61 const char TX_Multiplex[] PROGMEM = "Multiplex";
 62
 63 const char TX_EmxLogo[] PROGMEM = "Show EMX logo";
 64 const char TX_License[] PROGMEM = "Show license";
 65
 66 const char TX_ProfileNo[] PROGMEM = "Profile No.";
 67 const char TX_PValue[] PROGMEM = "P-Value";
 68 const char TX_IValue[] PROGMEM = "I-Value";
 69 const char TX_DValue[] PROGMEM = "D-Value";
 70
 71 const char TX_Curve[] PROGMEM = "Curve";
 72 const char TX_Flat[] PROGMEM = "Flat";
 73 const char TX_Normal[] PROGMEM = "Normal";
 74 const char TX_Steep[] PROGMEM = "Steep";
 75
 76 > const char TX_RunClock[] PROGMEM = "Run Clock";
 77 > const char TX_StopClock[] PROGMEM = "Stop Clock";
 78 > const char TX_ExitEMX[] PROGMEM = "Exit EMX";
 79 > const char TX_Started[] PROGMEM = "Clock started";
 80 > const char TX_Stopped[] PROGMEM = "Clock stopped";
 81 > const char TX_Menu[] PROGMEM = "Menu";
 82
 83 typedef struct
 84 {
 85 | uint8_t m_curveType;
 86 | uint8_t m_pValue;
 87 | uint8_t m_iValue;
 88 | uint8_t m_dValue;
 89 } Profile_t;
 90
 91 typedef struct EEProm
 92 {
 93 | uint8_t EEStart;
 94 | uint8_t m_contrast;
 95 | uint8_t m_voltageAlarm;
 96 | uint8_t m_protocol;
 97 | uint8_t m_curProfile;
 98 | Profile_t m_profiles[3];
 99 } EEProm_t;
100
101
102 extern EEProm_t EEProm;
103
104 #define EEP(name) ((uint8_t*) ((uint8_t*) &EEProm.name - &EEProm.EEStart))
105
106 #define EEP_PRV(name) (EEP(m_profiles[0].name) - EEP(m_profiles[0]))
107
108 const U8ValP_t EEVersion PROGMEM = {
109 .m_dataP = (uint8_t*) EEP(EEStart),
110 };
111
112 void setContrast(CallbackType_t aCbType, void* s32)
113 {
114



118
119
120 uint8_t val = ((S32MMSVal_t*) s32)->m_val;
121
122
123 uint8_t key = aCbType & 0xF0;
124
125
126 switch (aCbType & 0x0F)
127 {
128 case CT_ENTRY:
129 break;
130
131 case CT_CHANGE:
132 if (key == BT_ENTER)
133 eeprom_update_byte((uint8_t*)EEP(m_contrast), val);
134 else
135 lcdSetContrast(val);
136 break;
137 case CT_RETURN:
138 lcdSetContrast(val);
139 break;
140 }
141 }
142
143 void* getPrfDynDataP(void* aAdressOffset)
144 {
145
146
147
148
149
150
151 uint8_t curProf = eeprom_read_byte(EEP(m_curProfile));
152
153 return aAdressOffset + ( (int16_t) EEP(m_profiles[curProf-1]));
154 }
155
156 const U8MMValPCb_t Contrast PROGMEM = {
157 .m_min = 28,
158 .m_max = 50,
159 .m_dataP = (uint8_t*) EEP(m_contrast),
160 .m_callback = &setContrast,
161 };
162
163 const U8MMSValP_t Voltage PROGMEM = {
164 .m_min = 51,
165 .m_max = 125,
166 .m_scale = 1,
167 .m_dataP = (uint8_t*) EEP(m_voltageAlarm),
168 };
169
170
171 const U8MMValDP_t PValue PROGMEM = {
172 .m_min = 1,
173 .m_max = 100,
174
175 .m_dynDataInfo = (uint8_t*) EEP_PRV(m_pValue),
176 .m_callback = &getPrfDynDataP
177 };
178 const U8MMValDP_t IValue PROGMEM = {
179 .m_min = 0,
180 .m_max = 127,
181
182 .m_dynDataInfo = (uint8_t*) EEP_PRV(m_iValue),
183 .m_callback = &getPrfDynDataP
184 };
185 const U8MMValDP_t DValue PROGMEM = {
186 .m_min = 20,
187 .m_max = 80,
188
189 .m_dynDataInfo = (uint8_t*) EEP_PRV(m_dValue),
190 .m_callback = &getPrfDynDataP
191 };
192
193 const U8MMValP_t CurProfile PROGMEM = {
194 .m_min = 1,
195 .m_max = 3,
196 .m_dataP = (uint8_t*) EEP(m_curProfile),
197 };
198
199 const ITextListDP_t Curve PROGMEM = {
200 .m_entryCount = 3,
201 .m_dynDataInfo = (uint8_t*) EEP_PRV(m_curveType),
202 .m_callback = &getPrfDynDataP,
203 .m_texts = {
204 TX_Flat,
205 TX_Normal,
206 TX_Steep,
207 },
208 };
209
210 const ITextListP_t Protocol PROGMEM = {
211 .m_entryCount =5,
212 .m_idxP = (uint8_t*) EEP(m_protocol),
213 .m_texts = {
214 TX_Futaba,
215 TX_Spectrum,
216 TX_Graupner,
217 TX_Jeti,
218 TX_Multiplex
219 },
220 };
221
222 uint8_t Copyright(MenuState_t* aMs)
223 {
224 LCD_BUF_CLEAR();
225 lcdBufPuts(AT_PGM, PSTR("menu system,\n"
226 "framework and font\n"
227 "2013-2014 by\n"
228 "Edgar (emax) Hermanns"),
229 &Verdana11, 0, 0, COL_BLACK);
230 lcdUpdate(1);
231 pollButtons(0xFF, 1);
232 return 1;
233 }
234
235 > volatile uint8_t g_runClock = 0;
236
237 > uint8_t RunClock(MenuState_t* aMs)
238 > {
239 > g_runClock = 1;
240 > LCD_BUF_CLEAR();
241 > lcdBufPuts(AT_PGM, TX_Started, &Verdana19, 10, 25, COL_BLACK);
242 > lcdUpdate(1);
243 > pollButtons(BT_ALL, BF_DELAY);
244 > return 1;
245 > }
246
247 > uint8_t StopClock(MenuState_t* aMs)
248 > {
249 > g_runClock = 0;
250 > LCD_BUF_CLEAR();
251 > lcdBufPuts(AT_PGM, TX_Stopped, &Verdana19, 10, 25, COL_BLACK);
252 > lcdUpdate(1);
253 > pollButtons(BT_ALL, BF_DELAY);
254 > return 1;
255 > }
256
257 > uint8_t ExitEMX(MenuState_t* aMs)
258 > {
259 > return MR_EXIT;
260 > }
261
262 const Menu_t InfoMenu PROGMEM = {
263 | .m_entryCount = 5,
264 .m_entries = {
265 { TX_EmxLogo, VOID(0) },
266 { TX_License, VOID(0) },
267 > { TX_RunClock, FUNC(RunClock) },
268 > { TX_StopClock, FUNC(StopClock) },
269 > { TX_ExitEMX, FUNC(ExitEMX) },
270 },
271 };
272
273 const Menu_t TopMenu PROGMEM = {
274 .m_entryCount = 11,
275 .m_entries = {
276 { TX_Copyright, FUNC(Copyright) },
277 { TX_SubMenu, MENU(InfoMenu) },
278 { TX_EepromVersionRo, U8PER(EEVersion) },
279 { TX_EepromVersion, U8PE(EEVersion) },
280 { TX_SetContrast, U8MMPEC(Contrast) },
281 { TX_ScaledVoltage, U8MMSPE(Voltage) },
282 { TX_Protocol, ITLPE(Protocol) },
283 { TX_ProfileNo, U8MMPE(CurProfile) },
284 { TX_Curve, ITLDPE(Curve) },
285 { TX_PValue, U8MMDPE(PValue) },
286 { TX_IValue, U8MMDPE(IValue) },
287 { TX_DValue, U8MMDPE(DValue) },
288 },
289 };
290
291
292 > volatile uint8_t g_hrs;
293 > volatile uint8_t g_min;
294 > volatile uint8_t g_sec;
295 > volatile uint8_t g_sec100th;
296 > volatile uint8_t g_04ms;
297
298 > char clock[] = "00:00:00.00";
299
300 > void showClock(void)
301 > {
302 >
303 > lcdBufFillRect(0, 0, LCDWIDTH, LCDHEIGHT/2, COL_WHITE);
304 > lcdBufPuts(AT_RAM, clock, &Verdana19, 17, 20, COL_BLACK);
305 > }
306
307 > void initClockTimer(void)
308 > {
309 > TCCR0A = (1<<WGM01);
310 > TCCR0B |= (1 << CS01) | (1 << CS00);
311 > OCR0A = 124;
312 > TIMSK0 |= (1<<OCIE0A);
313 > }
314
315 > ISR (TIMER0_COMPA_vect)
316 > {
317 > if (g_runClock) {
318 > if (g_04ms < 24) ++g_04ms;
319 > else
320 > {
321 > g_04ms = 0;
322 > if (g_sec100th < 99) ++g_sec100th;
323 > else {
324 > g_sec100th = 0;
325 > if (g_sec < 59) ++g_sec;
326 > else {
327 > g_sec = 0;
328 > if (g_min < 59) ++g_min;
329 > else {
330 > g_min = 0;
331 > ++g_hrs;
332 > clock[0] = (g_hrs/10) + '0';
333 > clock[1] = (g_hrs%10) + '0';
334 > }
335 > clock[3] = (g_min/10) + '0';
336 > clock[4] = (g_min%10) + '0';
337 > }
338 > clock[6] = (g_sec/10) + '0';
339 > clock[7] = (g_sec%10) + '0';
340 > }
341 > uint8_t sec10th = g_sec100th/10;
342 > clock[9] = (sec10th) + '0';
343 > clock[10] = (g_sec100th%10) + '0';
344 > }
345 > }
346 > }
347
348 int main(void)
349 {
350 _delay_ms(100);
351 > initClockTimer();
352 > sei();
353 lcdInit();
354 BUTTON_INIT();
355 while(1)
356 > {
357 displayMenu(&TopMenu, BT_ALL);
358
359 > while (pollButtons(BT_ALL, BF_NOBLOCK) != BT_BACK)
360 > {
361 > LCD_BUF_CLEAR();
362 > showClock();
363 > lcdBufPuts(AT_PGM, TX_Menu, &Verdana11, 0, 50, COL_BLACK);
364 > lcdUpdate(1);
365 > }
366 > };
367 }
