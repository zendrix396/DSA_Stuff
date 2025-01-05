from graphviz import Digraph

def create_adder_subtractor_circuit():
    # Create a new directed graph
    dot = Digraph(comment='4-bit Binary Adder-Subtractor Circuit')
    dot.attr(rankdir='LR')
    
    # Set node attributes for better visualization
    dot.attr('node', shape='circle')
    
    # Add input nodes
    for i in range(4):
        dot.node(f'A{3-i}', f'A{3-i}')
        dot.node(f'B{3-i}', f'B{3-i}')
    
    # Add control signal M
    dot.node('M', 'M')
    
    # Add XOR gates for B input modification
    for i in range(4):
        dot.node(f'XOR{i}', 'XOR')
        dot.edge(f'B{3-i}', f'XOR{i}')
        dot.edge('M', f'XOR{i}')
    
    # Add full adder blocks
    for i in range(4):
        dot.node(f'FA{i}', 'FA')
        dot.edge(f'A{3-i}', f'FA{i}')
        dot.edge(f'XOR{i}', f'FA{i}')
        if i < 3:
            dot.edge(f'FA{i}', f'FA{i+1}', 'Carry')
    
    # Add output nodes
    for i in range(4):
        dot.node(f'S{3-i}', f'S{3-i}')
        dot.edge(f'FA{i}', f'S{3-i}')
    
    # Add carry out
    dot.node('Cout', 'Cout')
    dot.edge('FA3', 'Cout')
    
    # Example operation
    dot.attr(label='4-bit Binary Adder-Subtractor\nExample: A=1010, B=0111, M=1\nOperation: A-B')
    
    # Save the diagram
    dot.render('adder_subtractor_circuit', format='png', cleanup=True)

if __name__ == '__main__':
    create_adder_subtractor_circuit()
