#!/usr/bin/env python3

from TestHarness import Cluster, Node, ReturnType, TestHelper, Utils
import urllib.request
import sys

###############################################################
# http_plugin_tests.py
#
# Integration tests for HTTP plugin
#
###############################################################

Print=Utils.Print
errorExit=Utils.errorExit
cmdError=Utils.cmdError

args = TestHelper.parse_args({"-v","--clean-run", "--dump-error-details","--keep-logs"})
debug=args.v
killAll=args.clean_run
killAlaInstances = True
keepLogs = args.keep_logs
dumpErrorDetails = dumpErrorDetails=args.dump_error_details


Utils.Debug=debug
https_port = 5555
cluster=Cluster(host="127.0.0.1", walletd=True)

testSuccessful=False

ClientName="alacli"
timeout = .5 * 12 * 2 + 60 # time for finalization with 1 producer + 60 seconds padding
Utils.setIrreversibleTimeout(timeout)

try:
    TestHelper.printSystemInfo("BEGIN")

    Print("Stand up cluster")

    if cluster.launch(dontBootstrap=True, loadSystemContract=False, specificExtraAlanodeArgs = {0: "--http-validate-host true"}) is False:
        cmdError("launcher")
        errorExit("Failed to stand up ala cluster.")
    Print("Getting cluster info")
    cluster.getInfos()

    node0 = cluster.nodes[0]
    ## HTTP plugin listens to 127.0.0.1:8888 by default. With the --http-validate-host=true,
    ## the HTTP request to "http://localhost:8888" should fail because the HOST header doesn't
    ## match "127.0.0.1".

    def get_info_status(url):
        try:
            req = urllib.request.Request( url, method = "GET")
            return urllib.request.urlopen(req, data=None).code
        except urllib.error.HTTPError as response:
            return response.code
        except:
            e = sys.exc_info()[0]
            return e
    url = node0.endpointHttp.replace("127.0.0.1", "localhost") + "/v1/chain/get_info"
    code = get_info_status(url)
    assert code == 400, f"Expected HTTP returned code 400, got {code}"
    testSuccessful = True

finally:
    TestHelper.shutdown(cluster, None, testSuccessful, killAlaInstances, True, keepLogs, killAll, dumpErrorDetails)

exitCode = 0 if testSuccessful else 1
exit(exitCode)
