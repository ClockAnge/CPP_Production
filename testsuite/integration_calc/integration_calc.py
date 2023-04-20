import subprocess

def test_calculator():
    test_cases = [
        ("2+2\n", 4),
        ("3*4-1\n", 11),
        ("(1+2)*(3-4)\n", -3),
        ("2^3\n", 8)
    ]

    test_err = [
        ")",
        "(",
        "1-",
        "))",
        "("
    ]

    for test_case in test_cases:
        input_str, expected_output = test_case
        
        proc = subprocess.Popen(
            ["../../bin/calculator"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        
        stdout, stderr = proc.communicate(input_str)
        
        assert stdout.strip() == str(expected_output)
    
   
    for test_case in test_err:
        
        proc = subprocess.Popen(
            ["../../bin/calculator"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        
        stdout, stderr = proc.communicate(test_case)
    
        assert stderr.strip() == '''libc++abi: terminating with uncaught exception of type std::runtime_error: propusk'''
        
    print('All complete')


test_calculator()
