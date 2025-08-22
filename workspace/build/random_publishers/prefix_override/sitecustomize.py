import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/fredrik/dva502_master_thesis/Workspace/install/random_publishers'
