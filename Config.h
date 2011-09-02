#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <vector>
#include <string>

const int CONFIG_CTGS_CNT = 2;
const int DISP_STNGS_CNT = 4;
const int KEY_STNGS_CNT = 4;

const std::string CONFIG_CTGS_A[CONFIG_CTGS_CNT] = { "Display", 
						     "Keyboard" };
const std::vector<std::string> CONFIG_CTGS ( CONFIG_CTGS_A,
					     CONFIG_CTGS_A + 
					     CONFIG_CTGS_CNT );

const std::string DISP_STNGS_A[DISP_STNGS_CNT] = { "fullscreen", 
						   "screen_width", 
						   "screen_height", 
						   "color_depth" };
const std::vector<std::string> DISP_STNGS ( DISP_STNGS_A,
					    DISP_STNGS_A + 
					    DISP_STNGS_CNT );

const std::string KEY_STNGS_A[KEY_STNGS_CNT] =  { "UP", 
						  "DOWN", 
						  "LEFT", 
						  "RIGHT" };
const std::vector<std::string> KEY_STNGS ( KEY_STNGS_A,
					   KEY_STNGS_A + 
					   KEY_STNGS_CNT );

#endif
