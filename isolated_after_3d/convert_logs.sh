# path parameters
LOG_FILE_NAME="sirs_zhong.log01"
MA_FILE_NAME="sirs_zhong.ma"
SCENARIO_ROOT=${PWD}
PROJECT_ROOT=${SCENARIO_ROOT}"/.."
PARSER_PATH=${PROJECT_ROOT}"/tools/msg_log_parser"
PARSER_INPUT=${PARSER_PATH}"/input"
RAW_LOG_PATH=${SCENARIO_ROOT}"/logs_raw"
RESULTS_PATH=${SCENARIO_ROOT}"/logs_converted"

# pre processing necessicities
mkdir -p ${PARSER_PATH}"/input"
mkdir -p ${PARSER_PATH}"/output"
rm -f ${PARSER_PATH}"/output/messages.log"
rm -f ${PARSER_PATH}"/output/structure.json"
rm -f ${PARSER_PATH}"/input/"*
rm -f ${PARSER_PATH}"/"*".zip"
rm -rf ${PARSER_PATH}"/output\model"

# operations

# copy logfile to message parser input
cp ${RAW_LOG_PATH}"/"${LOG_FILE_NAME} ${PARSER_INPUT}
# copy ma file to message parser input
cp ${MA_FILE_NAME} ${PARSER_INPUT}

cd ${PARSER_INPUT}
mv ${LOG_FILE_NAME} "input_messages.log01"
mv ${MA_FILE_NAME} "model.ma"
cd ..
./runConverter.sh
unzip "output\model.zip" -d output
cp output/messages.log ${RESULTS_PATH}
cp output/structure.json ${RESULTS_PATH}
